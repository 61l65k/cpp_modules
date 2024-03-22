/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:28:12 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/22 05:28:18 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_HPP
#define HANDLERS_HPP

# define ERROR  -1 
# define SUCCESS 0
# define INVALID_MSG   "Invalid command. Please try again."
# define EXIT_MSG      "Exiting phonebook. Goodbye!"
# define EOF_MSG       "\nEOF detected. Exiting phonebook. Goodbye!"
# define MAIN_PROMPT   "Enter a command (ADD, SEARCH, or EXIT)> "
# define WELCOME_MSG   "Welcome to the phonebook!"

# include "PhoneBook.hpp"
# include <iostream>

enum e_input_type
{
    STRING,
    INTEGER
};

int         handle_add(PhoneBook& phoneBook);
void        handle_search(PhoneBook& phoneBook);
int         get_valid_input(const std::string& prompt, std::string& input);

#endif
