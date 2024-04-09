#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	// Default constructor
}

Ice::Ice(const Ice &src): AMateria(src)
{
	// Copy constructor
}

Ice::~Ice()
{
	// Destructor
}

Ice	&Ice::operator=(const Ice &src)
{
	if (this == &src)
		return (*this);
	AMateria::operator=(src);
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
