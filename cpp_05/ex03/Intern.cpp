#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

Intern::Intern(void) { }

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern(void) { }

Intern &	Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

AForm* Intern::makeForm(const std::string &nameForm, const std::string &target)
{
    const std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

    for (int i = 0; i < 3; ++i)
    {
        if (nameForm == formNames[i])
        {
            std::cout << YELLOW << "Intern creates " << formNames[i] << RESET << std::endl;
            switch (i)
            {
                case 0: return new PresidentialPardonForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new ShrubberyCreationForm(target);
            }
        }
    }
    
    std::cout << YELLOW << "[ Error! Form's name is incorrect.]" << RESET << std::endl;
    return nullptr;
}
