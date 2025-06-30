#include "order-processor.h"
#include "order.h"
#include <iostream>
#include <sstream>

std::vector<Order> OrderProcessor::validateOrders(const std::vector<Order> &rawOrders)
{
    std::vector<Order> result;

    for (auto &ord : rawOrders)
    {
        auto order = ord;

        bool valid{true};
        if (order.getItems().empty())
        {
            valid = false;
        }

        for (auto &item : order.getItems())
        {
            if (item.name.empty() || !item.price)
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            continue;
        }

        order.setStatus(OrderStatus::valid);

        result.push_back(order);
    }

    return result;
}

std::vector<Order> OrderProcessor::calculatePricing(const std::vector<Order> &validOrders)
{
    std::vector<Order> result;

    for (auto &ord : validOrders)
    {
        auto order = ord;
        double totalPrice{};

        for (auto &item : order.getItems())
        {
            totalPrice += item.price;
        }

        order.setTotalPrice(totalPrice);
        order.setStatus(OrderStatus::priced);
        result.push_back(order);
    }

    return result;
}

std::vector<Order> OrderProcessor::checkInventory(const std::vector<Order> &pricedOrders)
{
    std::vector<Order> result;

    for (auto &ord : pricedOrders)
    {
        bool available{true};

        for (auto &item : ord.getItems())
        {
            if (item.name == "apple" || item.name == "orange")
            {
                available = false;
                break;
            }
        }

        if (available)
        {
            auto order = ord;
            order.setStatus(OrderStatus::final);
            result.push_back(order);
        }
        else
        {
            continue;
        }
    }

    return result;
}

void OrderProcessor::generateInvoices(const std::vector<Order> &finalOrders)
{
    double totalPrice{};
    std::stringstream ss;
    ss << "=== Invoice ===\n";

    for (auto &ord : finalOrders)
    {
        totalPrice += ord.getTotalPrice();

        ss << "\nOrder #" << ord.getId() << "\n";
        ss << "Total price: " << ord.getTotalPrice() << "\n";
        for (auto &item : ord.getItems())
        {
            ss << "* " << item.name << ": " << item.price << '\n';
        }
    }

    ss << "\nTotal invoce price: " << totalPrice << "\n";

    std::cout << ss.str();
}