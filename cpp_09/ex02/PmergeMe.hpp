#include <deque>
#include <exception>
#include <vector>
#include <iostream>
#include <limits>
#include <ctime>
#include <deque>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int>   _vec;
        std::deque<int>    _deq;

        template <typename Container>
        void addElement(Container& container, const std::string& input);

        template <typename Container>
        void printContainer(const Container& container);

        void sortVectorContainer(std::vector<int>& container, unsigned int start, unsigned int end);
        void insertVectorContainer(std::vector<int>& container, unsigned int start, unsigned int end);
        void mergeVectorContainer(std::vector<int>& container, unsigned int start, unsigned int end);

        void sortDequeContainer(std::deque<int>& container, unsigned int start, unsigned int end);
        void insertDequeContainer(std::deque<int>& container, unsigned int start, unsigned int end);
        void mergeDequeContainer(std::deque<int>& container, unsigned int start, unsigned int end);

        bool validateInput(const std::string &input);

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &src);
        PmergeMe& operator=(PmergeMe &rhs);

        void sort(int argc);
        void addVec(const std::string &input);
        void addDeq(const std::string &input);

    class invalidInputException : public std::exception
    {
        const char *what() const throw();
    };
};
