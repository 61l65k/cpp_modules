#include "PmergeMe.hpp"

/*-------------------------------- CLASS IMPLEMENTATIONS --------------------------------*/

PmergeMe::PmergeMe() = default;

PmergeMe::PmergeMe(PmergeMe &src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe &rhs)
{
    (void) rhs;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    _vec.clear();
    _deq.clear();
}

/*-------------------------------- METHODS --------------------------------*/

void PmergeMe::addDeq(const std::string &input)
{
    addElement(_deq, input);
}

void PmergeMe::addVec(const std::string &input)
{
    addElement(_vec, input);
}

bool PmergeMe::validateInput(const std::string& input)
{
    if (input.length() > 10 || input[0] == '-')
        return false;
    
    if (!std::all_of(input.begin(), input.end(), ::isdigit))
        return false;
    
    if (std::atoll(input.c_str()) > std::numeric_limits<int>::max())
        return false;
    
    return true;
}


void PmergeMe::sort(int argc)
{
    std::cout << "Before: ";
    printContainer(_deq);
    std::clock_t beginVec = clock();
    sortVectorContainer(_vec, 0, _vec.size() - 1);
    std::clock_t endVec = clock();

    std::clock_t beginDeq = std::clock();
    sortDequeContainer(_deq, 0, _deq.size() - 1);
    std::clock_t endDeq = std::clock();

    std::cout << "After: ";
    printContainer(_deq);

    std::cout << "\nTime to sort a range of " << (argc - 1) << " with std::vector : ";
    std::cout << (static_cast<double>(endVec - beginVec) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
    std::cout << "Time to sort a range of " << (argc - 1) << " with std::deque : ";
    std::cout << (static_cast<double>(endDeq - beginDeq) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl << std::endl;
}

template <typename Container>
void PmergeMe::addElement(Container& container, const std::string& input)
{
    if (!validateInput(input))
        throw invalidInputException();
    container.push_back(std::atoi(input.c_str()));
}

template <typename Container>
void PmergeMe::printContainer(const Container& container)
{
    for (auto it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


/*-------------------------------- DEQUE --------------------------------*/

void PmergeMe::sortDequeContainer(std::deque<int>& container, unsigned int start, unsigned int end)
{
    if (end - start + 1 <= 2)
        insertDequeContainer(container, start, end);
    else if (end - start > 1)
    {
        const unsigned int middle = start + ((end - start) / 2);
        sortDequeContainer(container, start, middle);
        sortDequeContainer(container, middle + 1, end);
        mergeDequeContainer(container, start, end);
    }
}


void PmergeMe::insertDequeContainer(std::deque<int>& container, unsigned int start, unsigned int end)
{
    for (auto i = start + 1; i <= end; ++i)
    {
        for (auto j = i; j > start && container[j - 1] > container[j]; --j)
            std::swap(container[j], container[j - 1]);
    }
}

void PmergeMe::mergeDequeContainer(std::deque<int>& container, unsigned int start, unsigned int end)
{
    std::deque<int> tmp;
    const unsigned int split = start + (end - start) / 2 + 1;
    unsigned int left = start;
    unsigned int right = split;

    while (left < split && right <= end)
    {
        if (container[left] < container[right])
            tmp.push_back(container[left++]);
        else
            tmp.push_back(container[right++]);
    }
    while (left < split)
        tmp.push_back(container[left++]);
    while (right <= end)
        tmp.push_back(container[right++]);
    std::copy(tmp.begin(), tmp.end(), container.begin() + start);
}

/*-------------------------------- VECTOR --------------------------------*/

void PmergeMe::sortVectorContainer(std::vector<int>& container, unsigned int start, unsigned int end)
{
    if (end - start + 1 <= 2)
        insertVectorContainer(container, start, end);
    else if (end - start > 1)
    {
        const unsigned int middle = start + ((end - start) / 2);
        sortVectorContainer(container, start, middle);
        sortVectorContainer(container, middle + 1, end);
        mergeVectorContainer(container, start, end);
    }
}


void PmergeMe::insertVectorContainer(std::vector<int>& container, unsigned int start, unsigned int end)
{
    for (auto i = start + 1; i <= end; ++i)
    {
        for (auto j = i; j > start && container[j - 1] > container[j]; --j)
            std::swap(container[j], container[j - 1]);
    }
}

void PmergeMe::mergeVectorContainer(std::vector<int>& container, unsigned int start, unsigned int end)
{
    std::vector<int> tmp;
    const unsigned int split = start + (end - start) / 2 + 1;
    unsigned int left = start;
    unsigned int right = split;

    while (left < split && right <= end)
    {
        if (container[left] < container[right])
            tmp.push_back(container[left++]);
        else
            tmp.push_back(container[right++]);
    }
    while (left < split)
        tmp.push_back(container[left++]);
    while (right <= end)
        tmp.push_back(container[right++]);
    std::copy(tmp.begin(), tmp.end(), container.begin() + start);
}

/*-------------------------------- EXCEPTIONS --------------------------------*/

const char * PmergeMe::invalidInputException::what() const throw()
{
    return ("Error: invalid arguments");
}
