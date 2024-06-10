#pragma once 

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        void exec_action(const Bureaucrat &executioner) const;
        void changeTarget(std::string const & target);
        std::string const & getTarget() const;
        enum {e_gradeToSign = 72, e_gradeToExecute = 45};
    
    private:
        std::string _target;
};
