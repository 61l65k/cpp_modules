#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE) { }

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    checkGrade(grade);
    _grade = grade;
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) { }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out << bureaucrat.getName() << ", grade of " << bureaucrat.getName() << " " << bureaucrat.getGrade();
	return ( out );
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){ return ERR_GRADE_HIGH; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ERR_GRADE_LOW; }

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::checkGrade(int grade) const
{
    if (grade < MAX_GRADE)
    {
        throw GradeTooHighException();
    }
    else if (grade > MIN_GRADE)
    {
        throw GradeTooLowException();
    }
}
