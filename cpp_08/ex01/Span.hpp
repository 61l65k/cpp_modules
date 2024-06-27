#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int N;
    std::vector<int> tab;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    int shortestSpan();
    int longestSpan();

    template<typename Iterator>
    void insertRange(Iterator first, Iterator last)
    {
        typename std::iterator_traits<Iterator>::difference_type d = std::distance(first, last);
        if (d + tab.size() > N)
            throw std::runtime_error("Out of range!!");

        tab.insert(tab.end(), first, last);
    }
};
