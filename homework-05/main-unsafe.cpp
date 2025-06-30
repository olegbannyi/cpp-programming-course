#include "core/bank.h"
#include "core/cashier.h"
#include "core/logger.h"
#include "unsafe/unsafe-bank-account.h"
#include "unsafe/unsafe-bank-statistics.h"
#include "util/util.h"
#include <cstdlib>
#include <format>
#include <iostream>

using namespace banking::core;
using namespace banking::unsafe;

int main(int argc, char *argv[])
{
    const bool ref_version = banking::util::is_reference_mode(argc, argv);

    UnsafeBankAccount account;
    UnsafeBankStatistics statistics;

    double initial_balance{account.get_balance()};

    Bank bank;

    Casher cachier1(Logger(std::format("build/cachier-unsafe-{}.log", 1)), ref_version);
    Casher cachier2(Logger(std::format("build/cachier-unsafe-{}.log", 2)), ref_version);
    Casher cachier3(Logger(std::format("build/cachier-unsafe-{}.log", 3)), ref_version);
    Casher cachier4(Logger(std::format("build/cachier-unsafe-{}.log", 4)), ref_version);
    Casher cachier5(Logger(std::format("build/cachier-unsafe-{}.log", 5)), ref_version);

    bank.assign<UnsafeBankAccount, UnsafeBankStatistics>(cachier1, account, statistics);
    bank.assign<UnsafeBankAccount, UnsafeBankStatistics>(cachier2, account, statistics);
    bank.assign<UnsafeBankAccount, UnsafeBankStatistics>(cachier3, account, statistics);
    bank.assign<UnsafeBankAccount, UnsafeBankStatistics>(cachier4, account, statistics);
    bank.assign<UnsafeBankAccount, UnsafeBankStatistics>(cachier5, account, statistics);

    bank.waitAll();

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "=== Bank Simulation Results (Unsafe) ===\n"
              << "Initial balance: " << initial_balance << "\n"
              << "Final balance: " << account.get_balance() << "\n"
              << "Total transactions: " << statistics.get_total_transactions() << "\n"
              << "Total transaction amount: " << statistics.get_total_amount() << "\n"
              << "All cashiers completed work unsafely!" << std::endl;

    return 0;
}
