#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

struct Item
{
    std::string name;
    double price;
};

enum OrderStatus
{
    initial,
    valid,
    priced,
    final
};

class Order
{
  private:
    int id_;
    std::vector<Item> items_;
    double totalPrice_;
    OrderStatus status_;

  public:
    explicit Order(int id);
    int getId() const;
    std::vector<Item> getItems() const;
    double getTotalPrice() const;
    void setTotalPrice(double totalPrice);
    OrderStatus getStatus() const;
    void setStatus(const OrderStatus);
    void addItem(const Item);
};

#endif // ORDER_H
