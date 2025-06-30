#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

template <typename T>
using Visitor = std::function<void(const T &)>;

template <typename C, typename P>
void forEachWithRange(const C &, const Visitor<P> &);

template <typename C, typename P>
void forEachWithIterator(const C &, const Visitor<P> &);

template <typename C, typename P>
void goThroughContainer(const std::string &, const C &, const Visitor<P> &);

int main()
{
    const std::vector digits = {1, 2, 3, 4, 5};
    const Visitor<int> digitsPrinter = [](const int &d) -> void
    {
        std::cout << d << std::endl;
    };

    goThroughContainer("Vector", digits, digitsPrinter);

    const std::set<int> digitsSet = {6, 7, 8, 9, 10};

    goThroughContainer("Set", digitsSet, digitsPrinter);

    const std::map<std::string, std::string> fruits = {
        {"apple", "red"},
        {"lemon", "yellow"},
        {"peach", "pale yellowish-pink"}};
    const Visitor<std::pair<std::string, std::string>> fruitsPrinter =
        [](const std::pair<std::string, std::string> &pair) -> void
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    };

    goThroughContainer("Map", fruits, fruitsPrinter);

    return 0;
}

template <typename C, typename P>
void goThroughContainer(const std::string &title, const C &container, const Visitor<P> &visitor)
{
    std::cout << title << " with range:" << std::endl;
    forEachWithRange(container, visitor);
    std::cout << std::endl;
    std::cout << title << " with iterator:" << std::endl;
    forEachWithIterator(container, visitor);
    std::cout << std::endl;
}

template <typename C, typename P>
void forEachWithRange(const C &container, const Visitor<P> &visitor)
{
    for (const auto &element : container)
    {
        visitor(element);
    }
}

template <typename C, typename P>
void forEachWithIterator(const C &container, const Visitor<P> &visitor)
{
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        visitor(*it);
    }
}
