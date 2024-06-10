#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void executeTest(Bureaucrat &executor, AForm &form)
{
    try
    {
        std::cout << GREEN << executor << RESET << std::endl;
        executor.executeForm(form);
        std::cout << BLUE << form << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}

void signAndExecuteTest(Bureaucrat &signer, Bureaucrat &executor, AForm &form)
{
    try
    {
        std::cout << GREEN << signer << RESET << std::endl;
        form.beSigned(signer);
        std::cout << BLUE << form << RESET << std::endl;
        executeTest(executor, form);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}

int main(void)
{
    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Morty");
    PresidentialPardonForm pardon("Rick Sanchez");
    Bureaucrat mike("Mike", 150);
    Bureaucrat jon("Jon", 46);
    Bureaucrat steve("Steve", 3);

    std::cout << "\n === Test 1: Execute forms without being signed === \n\n";
    executeTest(steve, shrubbery);
    executeTest(steve, robotomy);
    signAndExecuteTest(steve, steve, pardon);

    std::cout << "\n === Test 2: Sign forms and execute without enough grade === \n\n";
    ShrubberyCreationForm jonShrubbery("Jon");
    RobotomyRequestForm jonRobot("Duke");
    signAndExecuteTest(jon, jon, jonShrubbery);
    signAndExecuteTest(jon, jon, jonRobot);
    signAndExecuteTest(jon, jon, pardon);

    ShrubberyCreationForm mikeShrubbery("Mike");
    signAndExecuteTest(mike, mike, mikeShrubbery);
    signAndExecuteTest(mike, mike, robotomy);
    signAndExecuteTest(mike, mike, pardon);

    std::cout << "\n === Test 3: Sign forms and execute them === \n\n";
    ShrubberyCreationForm steveShrubbery("Steve");
    RobotomyRequestForm steveRobot("Bob");
    signAndExecuteTest(steve, steve, steveShrubbery);
    signAndExecuteTest(steve, steve, steveRobot);
    signAndExecuteTest(steve, steve, pardon);

    std::cout << "\n === All tests completed === \n\n";
    return 0;
}
