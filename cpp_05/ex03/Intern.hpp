#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"

class Intern
{	
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		Intern &	operator=(Intern const &rhs);

		AForm *	makeForm(std::string const &nameForm, std::string const &target);
};
