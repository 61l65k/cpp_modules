#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", e_gradeToSign, e_gradeToExecute)
{
    _target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", e_gradeToSign, e_gradeToExecute)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
    _target = copy._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    if (this != &copy)
    {
        _target = copy._target;
    }
    return(*this);
}

void RobotomyRequestForm::exec_action(const Bureaucrat &executioner) const
{
    (void) executioner;
    std::cout << "Drilling noises... ";
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}

void RobotomyRequestForm::changeTarget(std::string const & target)
{
    _target = target;
}

const std::string & RobotomyRequestForm::getTarget() const
{
    return _target;
}
