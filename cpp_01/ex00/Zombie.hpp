/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:32:59 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 02:53:45 by apyykone         ###   ########.fr       */
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
        void announce() const;
};

void    randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif // ZOMBIE_HPP
