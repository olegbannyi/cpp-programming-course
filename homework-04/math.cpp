#include "math.h"

#include <cstddef>
#include <vector>

bool is_prime(const unsigned int value)
{
    if (value <= 3)
    {
        return true;
    }
    for (unsigned int i{2}; i < value; ++i)
    {
        if (value % i == 0)
        {
            return false;
        }
    }

    return true;
}

unsigned int fibonacci(const unsigned int value)
{
    if (value <= 1)
    {
        return 1;
    }

    return fibonacci(value - 2) + fibonacci(value - 1);
}

std::vector<unsigned int> prime_number_list(const unsigned int max)
{
    std::vector<unsigned int> result{};

    for (unsigned int i{1}; i <= max; ++i)
    {
        if (is_prime(i))
        {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<unsigned int> fibonacci_list(const unsigned int num)
{
    std::vector<unsigned int> result{};
    result.reserve(num);

    for (size_t i{0}; i < num; ++i)
    {
        result.push_back(fibonacci(i));
    }

    return result;
}

unsigned int factorial(const unsigned int value)
{
    unsigned int result{1};
    for (unsigned int i = 1; i <= value; ++i)
    {
        result *= i;
    }
    return result;
}

unsigned int sum_of_squares(const unsigned int value)
{
    unsigned int result{0};
    for (unsigned int i = 1; i <= value; ++i)
    {
        result += i * i;
    }
    return result;
}