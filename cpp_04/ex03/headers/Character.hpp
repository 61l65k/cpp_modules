#pragma once

#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
private:
	std::string	_name;
	AMateria	*_inventory[4];
public:
	Character();
	Character(const Character &src);
	Character(std::string const &name);
	~Character();
	Character	&operator=(const Character &src);

	std::string const 	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};
