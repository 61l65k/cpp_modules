#include"Span.hpp"

int main()
{
    try
    {
        Span mySpan(10);
        std::vector<int> list;
        list.push_back(1);
        list.push_back(3);
        list.push_back(4);
        list.push_back(10);
        mySpan.addNumber(6);
        mySpan.addNumber(52);
        mySpan.addNumber(17);
        mySpan.addNumber(9);
        mySpan.addNumber(11);
        mySpan.addRange<std::vector<int>::iterator , std::vector<int> >(list.begin(), list.end());
        std::cout << mySpan.longestSpan() << std::endl;
        std::cout << mySpan.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
