#pragma once

#include "logger.h"
#include <chrono>
#include <random>

namespace banking
{
namespace core
{

class Casher
{
    Logger logger_;
    bool referenceVersion_;
    const double referenceValue_;

  public:
    explicit Casher(Logger logger, bool referenceVersion = false)
        : logger_(std::move(logger)), referenceVersion_(referenceVersion), referenceValue_(100)
    {
    }
    template <class BankAccountType, class BankStatisticsType>
    void work(BankAccountType &account, BankStatisticsType &statistics)
    {
        std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> dist_deposit(50.0, 500.0);
        std::uniform_real_distribution<double> dist_withdraw(10.0, 200.0);

        double amount{};
        bool succes{};

        for (size_t i = 0; i < 50; ++i)
        {
            amount = referenceVersion_ ? referenceValue_ : dist_deposit(rng);
            account.deposit(amount);
            statistics.record_transaction(amount);
            logger_ << std::format("{:03d} deposite: {:.2f}, balance: {:.2f}\n", i, amount, account.get_balance());

            amount = referenceVersion_ ? referenceValue_ : dist_withdraw(rng);
            succes = account.withdraw(amount);
            statistics.record_transaction(amount);
            logger_ << std::format("    withdraw: {:.2f}, success: {}, balance: {:.2f}\n\n", amount, succes,
                                   account.get_balance());
        }

        logger_.flush();
    }
};
} // namespace core
} // namespace banking
