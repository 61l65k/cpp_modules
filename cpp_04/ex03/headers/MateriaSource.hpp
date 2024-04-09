#pragma once

#include "IMateriaSource.hpp"

#define MAX_MATERIA 4

class MateriaSource: public IMateriaSource
{
private:
	AMateria	*_materias[MAX_MATERIA];
public:
	MateriaSource(); // Default constructor
	MateriaSource(const MateriaSource &src); // Copy constructor
	~MateriaSource(); // Destructor
	MateriaSource	&operator=(const MateriaSource &src); // Assignment operator

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

};
