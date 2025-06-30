#include "order.h"
#include <vector>

Order::Order(int id) : id_(id), status_(OrderStatus::initial)
{
}

int Order::getId() const
{
    return id_;
}

std::vector<Item> Order::getItems() const
{
    return items_;
}

double Order::getTotalPrice() const
{
    return totalPrice_;
}

void Order::setTotalPrice(double totalPrice)
{
    totalPrice_ = totalPrice;
}

OrderStatus Order::getStatus() const
{
    return status_;
}

void Order::setStatus(const OrderStatus status)
{
    status_ = status;
}

void Order::addItem(const Item item)
{
    items_.push_back(item);
}