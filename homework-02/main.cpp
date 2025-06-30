#include <iostream>
#include <algorithm>
#include <vector>

class BigData
{
private:
    int *data;
    size_t size;

public:
    BigData(size_t size);
    ~BigData();

    // Конструктор копіювання
    BigData(const BigData &other);

    // Оператор копіювання
    BigData &operator=(const BigData &other);

    // Конструктор переміщення
    BigData(BigData &&other) noexcept;

    // Оператор переміщення
    BigData &operator=(BigData &&other) noexcept;

    void print() const;
};

BigData::BigData(size_t _size) : size(_size), data(new int[_size])
{
    std::cout << "Constructor called: BigData(size_t), size = " << _size << std::endl;
    std::fill(this->data, this->data + _size, 0);
}

BigData::~BigData()
{
    std::cout << "Destructor called: ~BigData(), size = " << size;
    if (nullptr != this->data)
    {
        std::cout << ", clean resource";
        delete[] this->data;
    }
    std::cout << std::endl;
}

BigData::BigData(const BigData &other) : size(other.size), data(new int[other.size])
{
    std::cout << "Copy constructor called: BigData(const BigData&), size = " << other.size << std::endl;
    std::copy(other.data, other.data + size, this->data);
}

BigData &BigData::operator=(const BigData &other)
{
    if (this != &other)
    {
        std::cout << "Copy assignment operator called: BigData& operator=(const BigData&), size = " << other.size << std::endl;
        if (nullptr != this->data)
        {
            delete[] this->data;
        }

        this->size = other.size;
        this->data = new int[other.size];
        std::copy(other.data, other.data + size, this->data);
    }

    return *this;
}

BigData::BigData(BigData &&other) noexcept : size(other.size), data(other.data)
{
    std::cout << "Move constructor called: BigData(BigData&&) noexcept, size = " << other.size << std::endl;

    other.data = nullptr;
    other.size = 0;
}

BigData &BigData::operator=(BigData &&other) noexcept
{
    if (this != &other)
    {
        std::cout << "Move assignment operator called: BigData& operator=(const BigData&&): size = " << other.size << std::endl;
        if (nullptr != this->data)
        {
            delete[] this->data;
        }

        this->size = other.size;
        this->data = other.data;

        other.data = nullptr;
        other.size = 0;
    }

    return *this;
}

void BigData::print() const
{
    std::cout << "[";

    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << *(this->data + i);
        if (i != this->size - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

BigData createBigDate(int size)
{
    BigData data(size);
    return data;
}

void printVector(const std::vector<int> &v)
{
    for (const auto &n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Create BigData createBigDate(7):" << std::endl;
    BigData first(0);
    first = createBigDate(7);
    first.print();
    std::cout << std::endl;

    std::cout << "Copy BigData:" << std::endl;
    BigData second(0);
    second = first;
    second.print();
    std::cout << std::endl;

    std::cout << "Move BigData:" << std::endl;
    BigData third(0);
    third = std::move(second);
    third.print();
    std::cout << std::endl;

    std::vector<int> numbers = {1, 3, 5, 7, 9};
    const auto boosting = [&numbers](int n)
    {
        for (auto item = numbers.begin(); item != numbers.end(); ++item)
        {
            *item += n;
        }
    };

    std::cout << "Print INITIAL vector 'numbers':" << std::endl;
    printVector(numbers);
    std::cout << std::endl;

    boosting(3);

    std::cout << "Print BOOSTED vector 'numbers':" << std::endl;
    printVector(numbers);
    std::cout << std::endl;

    return 0;
}