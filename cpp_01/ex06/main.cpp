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
* Shows all the complains
 * ./harlemfiter
* Shows only the complains above the given level. Exampe:
 * ./harlemfiter INFO

*/

int main( int argc, char **argv ) {
	Harl harl;

	if (argc > 1)
		harl.set_start_index(argv[1]);
	

	harl.complain_all();

	return 0;
}
