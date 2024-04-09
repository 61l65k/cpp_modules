#pragma once

#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice &src); 
	~Ice();
	Ice	&operator=(const Ice &src);

	AMateria	*clone() const;
	void		use(ICharacter& target);
};
