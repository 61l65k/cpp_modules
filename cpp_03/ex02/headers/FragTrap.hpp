/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:54 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/12 01:30:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
        FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &src);
		
        void highFivesGuys(void);
};

# endif
