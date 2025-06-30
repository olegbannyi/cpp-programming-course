#pragma once

namespace banking
{
namespace unsafe
{
class UnsafeBankAccount
{
  private:
    double balance = 1000.0; // Початковий баланс

  public:
    void deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};
} // namespace unsafe
} // namespace banking
