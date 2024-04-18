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

	ICharacter* keke = new Character("me");

	keke->equip(src->createMateria("ice"));
	keke->equip(src->createMateria("cure"));

	ICharacter* bob = new Character("bob");

	keke->use(0, *bob);
	keke->use(1, *bob);

	delete bob;
	delete keke;
	delete src;

	return 0;
}
