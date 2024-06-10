#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", e_gradeToSign, e_gradeToExecute)
{
    _target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", e_gradeToSign, e_gradeToExecute)
{
    _target = target;

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
    _target = copy._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		_target = copy._target;
	}
	return(*this);
}

void PresidentialPardonForm::exec_action(const Bureaucrat &executioner) const
{
    (void) executioner;
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::changeTarget(std::string const & target)
{
    _target = target;
}

const std::string & PresidentialPardonForm::getTarget() const
{
    return _target;
}
