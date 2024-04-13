/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:54 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:31:17 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :
		FragTrap();
        FragTrap(std::string name, bool not_derived);
		~FragTrap();
		FragTrap(const FragTrap &src, bool not_derived);
		FragTrap &operator=(const FragTrap &src);
		
        void highFivesGuys(void);
};

# endif
