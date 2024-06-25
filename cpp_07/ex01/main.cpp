#include <iostream>
#include <string>
#include "iter.hpp"

// Function to print an integer (non-template)
void printInt(const int &n) {
    std::cout << n << " ";
}

// Function to print a string (non-template)
void printString(const std::string &s) {
    std::cout << s << " ";
}

// Function template to increment a value (can be used as the third parameter)
template<typename T>
void increment(T &n) {
    ++n;
}

int main()
{
    // Test case 1: Printing integer elements
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Integer array: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;

    // Test case 2: Printing string elements
    std::string strArray[] = {"Hello", "world", "!"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array: ";
    iter(strArray, strLen, printString);
    std::cout << std::endl;

    // Test case 3: Modifying integer elements using a function template
    std::cout << "Original integer array: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;

    iter(intArray, intLen, increment<int>);

    std::cout << "Modified integer array: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;

    // Test case 4: Modifying string elements using a function template
    std::cout << "Original string array: ";
    iter(strArray, strLen, printString);
    std::cout << std::endl;

    return 0;
}
