/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:28:25 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/22 05:28:26 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "handlers.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::cout << WELCOME_MSG << std::endl;
    while (get_valid_input(MAIN_PROMPT, command) != ERROR)
    {
        if (command == "ADD") 
        {
            if (handle_add(phoneBook) < 0) break ;
        }
        else if (command == "SEARCH")
        {
            handle_search(phoneBook);
        }
        else if (command == "EXIT")
        {
            std::cout << EXIT_MSG << std::endl;
            break;
        }
        else
        {
            std::cout << INVALID_MSG << std::endl;
        }
    }
    return 0;
}
