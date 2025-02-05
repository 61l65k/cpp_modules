#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria();
	AMateria(const AMateria &src);
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria	&operator=(const AMateria &src);

	std::string const	&getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
