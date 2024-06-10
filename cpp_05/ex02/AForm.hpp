#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

#define ERR_FORM_NOT_SIGNED "::: ! Form is not signed ! :::"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        ~AForm();
        const std::string   &getName() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        bool                getSigned() const;
        void                beSigned(const Bureaucrat &bureaucrat);
        void                signForm(const Bureaucrat &bureaucrat);
        void                execute(const Bureaucrat &executor) const;

        virtual void        exec_action(const Bureaucrat &executioner) const = 0;

        using GradeTooHighException = Bureaucrat::GradeTooHighException;
        using GradeTooLowException = Bureaucrat::GradeTooLowException;
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);
