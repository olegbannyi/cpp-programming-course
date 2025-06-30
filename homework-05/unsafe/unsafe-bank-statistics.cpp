#include "unsafe-bank-statistics.h"

namespace banking
{
namespace unsafe
{
void UnsafeBankStatistics::record_transaction(double amount)
{
    transaction_count++;
    total_amount += amount;
}

int UnsafeBankStatistics::get_total_transactions() const
{
    return transaction_count;
}

double UnsafeBankStatistics::get_total_amount() const
{
    return total_amount;
}
} // namespace unsafe
} // namespace banking
