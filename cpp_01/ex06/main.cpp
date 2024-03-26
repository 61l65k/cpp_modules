/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:08:59 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/25 13:45:28 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * TESTS
 * 
 * * show all complaints *
 * ./harlFilter
 * 
 * * show complaints from DEBUG and above *
 * ./harlFilter DEBUG
 * 
 * * show all complaints from WARNING and above *
 * ./harlFilter WARNING
 * 
 * * show this message "[ Probably complaining about insignificant problems ]" *
 * ./harlFilter DEBUGGGGG
 * 
 * * show complaints from DEBUG and above *
 * ./harlFilter DEBUG AFSDF
*/

int main( int argc, char **argv ) {
	Harl harl;

	if (argc > 1)
		harl.setMinLevel(argv[1]);
	

	harl.complain_all();

	return 0;
}
