#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure &src);
	~Cure(); 
	Cure	&operator=(const Cure &src);

	AMateria	*clone() const;
	void		use(ICharacter& target);
};
