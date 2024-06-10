#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE) { }

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name), _grade(grade)
{
    checkGrade(grade);
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

void Bureaucrat::signForm(AForm& f)
{
	f.beSigned(*this);
    if (f.getSigned() == false)
		std::cout << this->_name << " couldnt sign '" << \
        f.getName()<<" cos grade not enough :(" << std::endl;
    else
        std::cout << this->_name << " signs '" << f.getName() << "'" << std::endl;
}

void    Bureaucrat::executeForm(AForm const &form){
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " cannot execute " \
        << form.getName() << " cos: " << e.what() << std::endl;
	}
}
