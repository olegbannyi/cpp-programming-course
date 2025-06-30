#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "worker.h"
#include <thread>
#include <vector>

class ThreadPool
{
    std::vector<std::thread> threads_;

  public:
    explicit ThreadPool(size_t size)
    {
        threads_.resize(size);
    }
    template <typename R, typename... A> void addWorker(Worker<R, A...> &&worker, A &&...args)
    {
        threads_.emplace_back(&Worker<R, A...>::run, &worker, args...);
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
    ~ThreadPool()
    {
        waitAll();
    }
};

#endif // THREAD_POOL_H