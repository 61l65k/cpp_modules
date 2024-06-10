#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MAX_GRADE)
{
}

AForm::AForm(const AForm &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() { }

AForm	&AForm::operator=(const AForm &src)
{
	if (this != &src)
	    _signed = src._signed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, const AForm &f )
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

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool AForm::getSigned() const
{
	return _signed;
}

std::string const &AForm::getName() const
{
	return _name;
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > _gradeToExecute)
	{
		throw AForm::GradeTooLowException();
	}
	exec_action(executor);
}

const char* AForm::FormNotSignedException::what() const throw() { return ERR_FORM_NOT_SIGNED; }
