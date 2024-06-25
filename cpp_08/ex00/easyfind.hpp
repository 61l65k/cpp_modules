#pragma once
#include<iostream>
#include<algorithm>
template<typename T>

void easyfind(T tab, int x)
{
    typename T::iterator itr;
    itr = std::find(tab.begin(),tab.end(),x);
    if (itr != tab.end())
    {
        std::cout << "Element : " << x ;
        std::cout << " fond in index " << itr - tab.begin() << std::endl;  
    }
    else
        throw std::runtime_error("number not fond !!");
}