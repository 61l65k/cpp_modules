#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", e_gradeToSign, e_gradeToExecute) 
{
    _target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", e_gradeToSign, e_gradeToExecute)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    _target = copy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if (this != &copy)
    {
        _target = copy._target;
    }
    return(*this);
}

void    ShrubberyCreationForm::exec_action(Bureaucrat const &executioner) const
{
	std::ofstream	outfile;

    (void) executioner;
	outfile.open((_target +  "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cout << ERR_OPEN_TREE_FILE << std::endl;
		return ;
	}
	outfile << _target << TREE;
	outfile.close();
	std::cout << executioner.getName() << " successfully created a shrubbery " << std::endl;
}

void ShrubberyCreationForm::changeTarget(std::string const & target)
{
    _target = target;
}

const std::string & ShrubberyCreationForm::getTarget() const
{
    return _target;
}
