/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:32:59 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 03:28:54 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie {

    private:
        std::string name;
    
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void	give_name(std::string new_name);
        void    announce() const;
};
Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP
