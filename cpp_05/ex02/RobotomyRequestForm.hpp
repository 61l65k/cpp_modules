#pragma once 

#include "Form.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        void execute(const Bureaucrat &executor) const;
        enum {gradeToSign = 72, gradeToExecute = 45};
};
