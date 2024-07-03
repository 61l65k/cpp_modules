#include "PmergeMe.hpp"
#include <algorithm>

int main(int argc, char **argv)
{
    long long int dataVecTime = 0;
    long long int dataDeqTime = 0;
    long long int qsortVecTime = 0;
    long long int qsortDeqTime = 0;
    int i = 1;
    PmergeMe FJ;
    std::vector<int> sortVec;
    std::deque<int>  sortDeq;

    if (argc <= 2)
    {
        std::cout << "Error : usage ./PmergeMe 3 2 1 ..." << std::endl;
        return (1);
    }

    while (i < argc)
    {
        try
        {
            std::clock_t startDataVec = std::clock();
            FJ.addVec(argv[i]);
            std::clock_t endDataVec = std::clock();
            dataVecTime += endDataVec - startDataVec;

            std::clock_t startDataDeq = std::clock();
            FJ.addDeq(argv[i]);
            std::clock_t endDataDeq = std::clock();
            dataDeqTime += endDataDeq - startDataDeq;

            sortVec.push_back(std::atoi(argv[i]));
            sortDeq.push_back(std::atoi(argv[i]));
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return (1);
        }
        i++;
    }

    std::cout << "\nTime to construct a range of " << (argc - 1) << " with std::vector : ";
    std::cout << (static_cast<double>(dataVecTime) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
    std::cout << "Time to construct a range of " << (argc - 1) << " with std::deque : ";
    std::cout << (static_cast<double>(dataDeqTime) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl << std::endl;

    try
    {
        FJ.sort(argc);
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }

    std::cout << "\n\nCOMPARE WITH std::sort that uses introsort (hybrid of quicksort, heapsort, and insertion sort)\n" << std::endl;
    try
    {
        std::clock_t startQsortVec = std::clock();
        std::sort(sortVec.begin(), sortVec.end());
        std::clock_t endQsortVec = std::clock();
        qsortVecTime = endQsortVec - startQsortVec;

        std::clock_t startQsortDeq = std::clock();
        std::sort(sortDeq.begin(), sortDeq.end());
        std::clock_t endQsortDeq = std::clock();
        qsortDeqTime = endQsortDeq - startQsortDeq;

        std::cout << "Time to sort a range of " << (argc - 1) << " with std::vector (std::sort): ";
        std::cout << (static_cast<double>(qsortVecTime) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
        std::cout << "Time to sort a range of " << (argc - 1) << " with std::deque (std::sort): ";
        std::cout << (static_cast<double>(qsortDeqTime) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    return 0;
}
