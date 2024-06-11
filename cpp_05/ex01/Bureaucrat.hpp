#pragma once

#include <iostream>
#include <exception>

#define MAX_GRADE 1
#define MIN_GRADE 150
#define ERR_GRADE_LOW "::: ! Grade is too low ! :::"
#define ERR_GRADE_HIGH "::: ! Grade is too high ! :::"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        void                checkGrade(unsigned int grade) const;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, unsigned int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        const std::string &getName() const;
        int                getGrade() const;
        void               incrementGrade();
        void               decrementGrade();
        void			   signForm(Form& f);
        class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char* what() const throw();
        };
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );
