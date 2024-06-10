#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
        void exec_action(const Bureaucrat &executioner) const;
        void changeTarget(std::string const & target);
        std::string const & getTarget() const;
        enum grades{e_gradeToSign = 25, e_gradeToExecute = 5};
};
