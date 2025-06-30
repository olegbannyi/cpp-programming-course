#pragma once

#include "cashier.h"
#include <functional>
#include <thread>
#include <vector>

namespace banking
{
namespace core
{

class Bank
{
    std::vector<std::thread> threads_;

  public:
    ~Bank()
    {
        waitAll();
    }
    template <class BankAccountType, class BankStatisticsType>
    void assign(Casher &cachier, BankAccountType &account, BankStatisticsType &statistics)
    {
        threads_.emplace_back(&Casher::work<BankAccountType, BankStatisticsType>, &cachier, std::ref(account),
                              std::ref(statistics));
    }

    void waitAll()
    {
        for (auto &t : threads_)
        {
            if (t.joinable())
            {
                t.join();
            }
        }

        threads_.clear();
    }
};
} // namespace core
} // namespace banking
