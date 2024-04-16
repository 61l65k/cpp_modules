#pragma once

#include "IMateriaSource.hpp"

#define MAX_MATERIA 4

class MateriaSource: public IMateriaSource
{
private:
	AMateria	*_materias[MAX_MATERIA];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();
	MateriaSource	&operator=(const MateriaSource &src);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

};
