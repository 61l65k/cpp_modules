#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

template<typename Stack>
void printStack(Stack stack)
{
    typename Stack::iterator it = stack.begin();
    typename Stack::iterator ite = stack.end();
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int main()
{
    // Using default container (std::deque)
    MutantStack<int> defaultStack;
    defaultStack.push(10);
    defaultStack.push(20);
    defaultStack.push(30);
    std::cout << "MutantStack with std::deque (default):" << std::endl;
    printStack(defaultStack);

    // Using std::vector as the underlying container
    MutantStack<int, std::vector<int> > vectorStack;
    vectorStack.push(40);
    vectorStack.push(50);
    vectorStack.push(60);
    std::cout << "MutantStack with std::vector:" << std::endl;
    printStack(vectorStack);

    // Using std::list as the underlying container
    MutantStack<int, std::list<int> > listStack;
    listStack.push(70);
    listStack.push(80);
    listStack.push(90);
    std::cout << "MutantStack with std::list:" << std::endl;
    printStack(listStack);

    // Comparison with std::list directly
    std::list<int> lst;
    lst.push_back(70);
    lst.push_back(80);
    lst.push_back(90);
    std::cout << "std::list directly:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "std::list in reverse directly:" << std::endl;
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    return 0;
}

