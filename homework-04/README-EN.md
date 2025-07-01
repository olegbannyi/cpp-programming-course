# C++ programming course [👈](../README.md)

## HW #4: Multithreading (basics) [🇺🇦👈](./README.md)

### Task

***Task 1: Parallel calculation of mathematical functions***

Create a program that calculates various mathematical functions in separate threads:

- Thread 1: calculates the factorial of 15
- Thread 2: finds the sum of squares of numbers from 1 to 1000
- Thread 3: calculates Fibonacci numbers up to the 30th element
- Thread 4: finds all prime numbers up to 100

Each thread outputs its own result independently of the others. Threads must be in a thread pool, not created separately!

***Task 2: Order Processing System***

```cpp
class Order {
private:
    int id;
    std::vector<std::string> items;
    double totalPrice;
    std::string status;
public:
    // constructors, methods for order processing
};

class OrderProcessor {
public:
    std::vector<Order> validateOrders(const std::vector<Order>& rawOrders);
    std::vector<Order> calculatePricing(const std::vector<Order>& validOrders);
    std::vector<Order> checkInventory(const std::vector<Order>& pricedOrders);
    void generateInvoices(const std::vector<Order>& finalOrders);
};
```

***Requirements:***

Create a system where:

- Thread 1: validates initial orders (checks format, data correctness)
- Thread 2: waits for **Thread 1** to complete, calculates prices for valid orders
- Thread 3: waits for **Thread 2**, checks for stock availability
- Thread 4: waits for **Thread 3**, generates invoices and sends to customers

### Compile and run

```bash
~$ cd ./homework-04
~$ make
```
