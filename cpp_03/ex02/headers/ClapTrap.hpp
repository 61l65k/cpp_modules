/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:49:22 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:14:03 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream> 
# include <iomanip>

# define RED        "\033[31m"
# define GREEN      "\033[32m"
# define YELLOW     "\033[33m"
# define BLUE       "\033[34m"
# define MAGENTA    "\033[35m"
# define RESET      "\033[0m"

class ClapTrap {

public:
    ClapTrap();
    ClapTrap(const std::string& name, bool init_clap);
    ClapTrap(const ClapTrap &clapTrap, bool init_clap);
    ClapTrap & operator=(ClapTrap const & rhs);
    ~ClapTrap();
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);



protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
    bool         shouldInit;
    void init_trap(const std::string& title, const std::string &real_name);
    void destruct_trap(const std::string &real_name, const std::string& class_name);
    void copy_assigment_msg(const std::string& class_name, const std::string& name);
    void copy_constructor_msg(const std::string &class_name, const std::string &name);
};

#endif
