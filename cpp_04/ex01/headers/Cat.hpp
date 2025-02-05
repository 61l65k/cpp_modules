/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:39:14 by alex              #+#    #+#             */
/*   Updated: 2024/04/18 17:48:03 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

  private:
    Brain	*brain;

  public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	Cat &operator=(const Cat &copy);

	void makeSound() const;
};

#endif

