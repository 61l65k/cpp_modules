/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:08:59 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/25 13:37:35 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main( void ) {
	Harl harl;

    // Valid complains
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
    harl.complain("DEBUG");

    // Invalid complains
	harl.complain("DEBUGGGG");
	harl.complain("");
	
	return 0;
}