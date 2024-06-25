#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &n)
{
    std::cout << n << " ";
}

template<typename T>
void increment(T &n)
{
    ++n;
}

int main()
{
    // Integer array
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    // String array
    std::string strArray[] = {"Hello", "world", "!"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Integer array: ";
    iter(intArray, intLen, print<int>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, strLen, print<std::string>);
    std::cout << std::endl;

    iter(intArray, intLen, increment<int>);

    std::cout << "Modified integer array: ";
    iter(intArray, intLen, print<int>);
    std::cout << std::endl;

    std::cout << "Original string array: ";
    iter(strArray, strLen, print<std::string>);
    std::cout << std::endl;

    return 0;
}
