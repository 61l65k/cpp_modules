/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:40:10 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/01 19:58:09 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private :
    std::string _name;


public :
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &src);
    ~DiamondTrap(void);

    DiamondTrap & operator =(DiamondTrap const & src);

    void whoAmI(void); 
    using FragTrap::attack;

};

#endif