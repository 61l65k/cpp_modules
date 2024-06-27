#include"easyfind.hpp"
#include<vector>

int main()
{
    std::vector<int>vec;
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(17);
    vec.push_back(18);
    vec.push_back(17);
    try
    {
        easyfind(vec, 89);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       try
    {
        easyfind(vec, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       try
    {
        easyfind(vec, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
