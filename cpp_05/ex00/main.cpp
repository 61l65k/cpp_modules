#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b1("Alice", 151); //GradeTooLowException
        std::cout << b1 << std::endl; //Not executed
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Bob", 0); // GradeTooHighException
        std::cout << b2 << std::endl; //Not executed
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 100); // Legit
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
