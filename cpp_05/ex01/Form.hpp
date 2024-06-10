#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form();
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        ~Form();
        const std::string   &getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                getSigned() const;
        void                beSigned(const Bureaucrat &bureaucrat);
        void                signForm(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);
