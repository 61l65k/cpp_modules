#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
void easyfind(T tab, int x)
{
    typename T::iterator itr = std::find(tab.begin(), tab.end(), x);
    if (itr != tab.end())
    {
        std::cout << "Element : " << x ;
        std::cout << " found in index |" << itr - tab.begin() << "|" << std::endl;  
    }
    else
    {
        throw std::runtime_error("number not found in the container :(");
    }
}
