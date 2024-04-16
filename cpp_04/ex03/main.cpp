#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*
    Demonstrates polymorphism and interfaces in an RPG game scenario.
    - Interfaces: IMateriaSource, ICharacter
    - Classes: MateriaSource, AMateria, Ice, Cure, Character
    - Actions: Learn and use materia

	- Interfaces are used to define the methods that must-
	be implemented by the classes that inherit from them.

*/

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
