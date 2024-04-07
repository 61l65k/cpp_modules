/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:39:14 by alex              #+#    #+#             */
/*   Updated: 2024/04/07 16:20:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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