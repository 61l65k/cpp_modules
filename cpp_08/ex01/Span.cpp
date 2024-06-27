#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) : N(other.N), tab(other.tab) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        N = other.N;
        tab = other.tab;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (tab.size() >= N)
        throw std::runtime_error("Out of range!!");

    tab.push_back(num);
}

int Span::shortestSpan()
{
    if (tab.size() <= 1)
        throw std::runtime_error("No span can be found!!");

    std::vector<int> sortTab = tab;
    std::sort(sortTab.begin(), sortTab.end());

    int minSpan = sortTab[1] - sortTab[0];
    for (size_t i = 2; i < sortTab.size(); ++i)
    {
        int candidate = sortTab[i] - sortTab[i - 1];
        minSpan = std::min(minSpan, candidate);
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (tab.size() <= 1)
        throw std::runtime_error("No span can be found!!");

    int maxElement = *std::max_element(tab.begin(), tab.end());
    int minElement = *std::min_element(tab.begin(), tab.end());
    return maxElement - minElement;
}
