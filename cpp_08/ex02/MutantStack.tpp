#include "MutantStack.hpp"

#define TEMPLATE template<typename T, typename Container>


TEMPLATE
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

TEMPLATE
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

TEMPLATE
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T, Container>::operator=(other);
    }
    return *this;
}

TEMPLATE
MutantStack<T, Container>::~MutantStack() {}

TEMPLATE
typename Container::iterator MutantStack<T, Container>::begin() { return this->c.begin(); }

TEMPLATE
typename Container::iterator MutantStack<T, Container>::end() { return this->c.end(); }

TEMPLATE
typename Container::const_iterator MutantStack<T, Container>::begin() const { return this->c.begin(); }

TEMPLATE
typename Container::const_iterator MutantStack<T, Container>::end() const { return this->c.end(); }

TEMPLATE
typename Container::reverse_iterator MutantStack<T, Container>::rbegin() { return this->c.rbegin(); }

TEMPLATE
typename Container::reverse_iterator MutantStack<T, Container>::rend() { return this->c.rend(); }

TEMPLATE
typename Container::const_reverse_iterator MutantStack<T, Container>::rbegin() const { return this->c.rbegin(); }

TEMPLATE
typename Container::const_reverse_iterator MutantStack<T, Container>::rend() const { return this->c.rend(); }
