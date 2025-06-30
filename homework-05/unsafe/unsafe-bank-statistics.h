#pragma once

namespace banking
{
namespace unsafe
{

class UnsafeBankStatistics
{
  private:
    int transaction_count = 0;
    double total_amount = 0.0;

  public:
    void record_transaction(double amount);
    int get_total_transactions() const;
    double get_total_amount() const;
};
} // namespace unsafe
} // namespace banking
