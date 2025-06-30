#pragma once

#include <atomic>

namespace banking
{
namespace safe
{

class SafeBankStatistics
{
  private:
    std::atomic<int> transaction_count_{0}; // TODO: Використайте atomic
    std::atomic<double> total_amount_{0.0}; // TODO: Використайте atomic

  public:
    void record_transaction(double amount);
    int get_total_transactions() const;
    double get_total_amount() const;
};
} // namespace safe
} // namespace banking
