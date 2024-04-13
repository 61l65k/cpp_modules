/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:40:10 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:40:52 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private :
    std::string name;


public :
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &src);
    ~DiamondTrap(void);
    DiamondTrap & operator =(const DiamondTrap & src);

    void whoAmI(void); 
    using ScavTrap::attack;
};

#endif
