#include "safe-bank-account.h"
#include <mutex>

namespace banking
{
namespace safe
{
void SafeBankAccount::deposit(double amount)
{
    std::lock_guard<std::mutex> lock(balance_mutex_);
    balance_ += amount;
}

bool SafeBankAccount::withdraw(double amount)
{
    std::lock_guard<std::mutex> lock(balance_mutex_);
    if (balance_ >= amount)
    {
        balance_ -= amount;
        return true;
    }
    return false;
}

double SafeBankAccount::get_balance() const
{
    std::lock_guard<std::mutex> lock(balance_mutex_);
    return balance_;
}

} // namespace safe
} // namespace banking
