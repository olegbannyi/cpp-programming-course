#pragma once

#include <mutex>

namespace banking
{
namespace safe
{
class SafeBankAccount
{
  private:
    double balance_{1000.0};
    mutable std::mutex balance_mutex_;

  public:
    void deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
} // namespace safe
} // namespace banking
