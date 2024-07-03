#include <deque>
#include <exception>
#include <vector>
#include <iostream>
#include <limits>
#include <ctime>
#include <deque>

class PmergeMe
{
    private:
        std::vector<unsigned int>   _vec;
        std::deque<unsigned int>    _deq;

        template <typename Container>
        void addElement(Container& container, const std::string& input);

        template <typename Container>
        void sortContainer(Container& container, unsigned int start, unsigned int end);

        template <typename Container>
        void insertContainer(Container& container, unsigned int start, unsigned int end);

        template <typename Container>
        void mergeContainer(Container& container, unsigned int start, unsigned int end);

        template <typename Container>
        void printContainer(const Container& container);

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
