#ifndef ORDER_PROCESSOR_H
#define ORDER_PROCESSOR_H

#include "order.h"
#include <vector>

class OrderProcessor
{
  public:
    std::vector<Order> validateOrders(const std::vector<Order> &rawOrders);
    std::vector<Order> calculatePricing(const std::vector<Order> &validOrders);
    std::vector<Order> checkInventory(const std::vector<Order> &pricedOrders);
    void generateInvoices(const std::vector<Order> &finalOrders);
};

#endif // ORDER_PROCESSOR_H