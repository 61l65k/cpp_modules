#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MAX_GRADE)
{
}

Form::Form(const Form &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::~Form() { }

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
	    _signed = src._signed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, const Form &f )
{
	o << "---------------- Form: " << f.getName() << " ----------------" << std::endl;
	o << "Signed: " ;
	if (f.getSigned() == 0)
		o << "false" << std::endl;
	else
		o << "true" << std::endl;
	o << "Minimum grade to be signed: " << f.getGradeToSign() << std::endl;
	o << "Minimum grade to be executed: " << f.getGradeToExecute() << std::endl;
	o << "------------------------------------------------" << std::endl;
	return (o);
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool Form::getSigned() const
{
	return _signed;
}

std::string const &Form::getName() const
{
	return _name;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	_signed = true;
}
