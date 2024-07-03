#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    int i = 1;
    PmergeMe FJ;
    if (argc <= 2)
    {
        std::cout << "Error : usage ./PmergeMe 3 2 1 ..." << std::endl;
        return (1);
    }
    while (i < argc)
    {
        try
        {
            FJ.addVec(argv[i]);
            FJ.addDeq(argv[i]);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return (1);
        }
        i++;
    }
    try
    {
        FJ.sort(argc);
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    return (0);
}
