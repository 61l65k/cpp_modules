#include "Span.hpp"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(100);
        sp.addNumber(17);
        sp.addNumber(1);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span mySpan(10);
        int arr[] = {1, 3, 4, 10};
        std::vector<int> list(arr, arr + sizeof(arr) / sizeof(int));
        mySpan.addNumber(6);
        mySpan.addNumber(52);
        mySpan.addNumber(17);
        mySpan.addNumber(9);
        mySpan.addNumber(11);
        mySpan.insertRange(list.begin(), list.end());

        std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span sp(10000);
        std::vector<int> largeList(10000);
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (int i = 0; i < 10000; ++i)
        {
            largeList[i] = std::rand() % 100000;
        }
        
        sp.insertRange(largeList.begin(), largeList.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span sp(5);
        int arr[] = {1, 2, 3, 4, 5, 6};
        std::vector<int> list(arr, arr + sizeof(arr) / sizeof(int));
        sp.insertRange(list.begin(), list.end());
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
