#include "math.h"
#include "order-processor.h"
#include "order.h"
#include "thread-pool.h"
#include "worker.h"
#include <chrono>
#include <format>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::function<void(unsigned int)> get_result_printer(const std::string &name);

std::function<void(std::vector<unsigned int>)> get_list_printer(const std::string &name);

std::vector<Order> init_orders();

void wait_for_status(const std::vector<Order> &, const OrderStatus);

int main()
{
    ThreadPool mathPool(4);

    Worker<unsigned int, unsigned int> w1("sum_of_squares", sum_of_squares, get_result_printer("Sum of squares"));
    Worker<unsigned int, unsigned int> w2("factorial", factorial, get_result_printer("Factorial"));
    Worker<std::vector<unsigned int>, unsigned int> w3("prime_number_list", prime_number_list,
                                                       get_list_printer("Prime numbers"));
    Worker<std::vector<unsigned int>, unsigned int> w4("fibonacci_list", fibonacci_list,
                                                       get_list_printer("Fibonacci numbers"));

    mathPool.addWorker<unsigned int, unsigned int>(std::move(w1), 1000);
    mathPool.addWorker<unsigned int, unsigned int>(std::move(w2), 15);
    mathPool.addWorker<std::vector<unsigned int>, unsigned int>(std::move(w3), 100);
    mathPool.addWorker<std::vector<unsigned int>, unsigned int>(std::move(w4), 30);

    mathPool.waitAll();

    std::cout << "\n\n>>> Order processing <<<\n" << std::endl;

    ThreadPool orderProcessinPool(4);

    std::vector<Order> orders{init_orders()};

    OrderProcessor processor;

    Worker<std::vector<Order>> op_w1(
        "validation", [&processor, &orders]() -> std::vector<Order> { return processor.validateOrders(orders); },
        [&orders](std::vector<Order> result) { orders = result; });

    Worker<std::vector<Order>> op_w2(
        "pricing",
        [&processor, &orders]() -> std::vector<Order> {
            wait_for_status(orders, OrderStatus::valid);
            return processor.calculatePricing(orders);
        },
        [&orders](std::vector<Order> result) { orders = result; });

    Worker<std::vector<Order>> op_w3(
        "inventory",
        [&processor, &orders]() -> std::vector<Order> {
            wait_for_status(orders, OrderStatus::priced);
            return processor.checkInventory(orders);
        },
        [&orders](std::vector<Order> result) { orders = result; });

    Worker<std::vector<Order>> op_w4(
        "invoice",
        [&processor, &orders]() -> std::vector<Order> {
            wait_for_status(orders, OrderStatus::final);
            processor.generateInvoices(orders);
            return orders;
        },
        [&orders](std::vector<Order> result) { orders = result; });

    orderProcessinPool.addWorker<std::vector<Order>>(std::move(op_w1));
    orderProcessinPool.addWorker<std::vector<Order>>(std::move(op_w2));
    orderProcessinPool.addWorker<std::vector<Order>>(std::move(op_w3));
    orderProcessinPool.addWorker<std::vector<Order>>(std::move(op_w4));

    orderProcessinPool.waitAll();

    return 0;
}

std::function<void(unsigned int)> get_result_printer(const std::string &name)
{
    return [name](unsigned int res) { std::cout << std::format("=== {} ===\n{}\n", name, res); };
}

std::function<void(std::vector<unsigned int>)> get_list_printer(const std::string &name)
{
    return [name](const std::vector<unsigned int> &res) {
        std::stringstream ss;
        ss << std::format("=== {} ===\n", name);
        for (const auto &v : res)
        {
            ss << v << " ";
        }
        std::cout << std::format("{}\n", ss.str());
    };
}

std::vector<Order> init_orders()
{
    Order ord1(1);
    ord1.addItem({"tomato", 12.23});
    ord1.addItem({"apricot", 23.45});

    Order ord2(2);
    ord2.addItem({"orange", 10.23});
    ord2.addItem({"pear", 40.23});

    std::vector<Order> orders{ord1, ord2};

    return orders;
}

void wait_for_status(const std::vector<Order> &orders, const OrderStatus status)
{
    if (!orders.empty())
    {
        while (true)
        {
            int valid{0};
            for (auto &ord : orders)
            {
                if (ord.getStatus() == status)
                {
                    ++valid;
                }
            }
            if (orders.size() == valid)
            {
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
