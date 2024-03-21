#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include "PhoneBook.hpp"
#include <iostream>

int         handle_add(PhoneBook& phoneBook);
void        handle_search(PhoneBook& phoneBook);
void        handle_exit();
int         get_valid_input(const std::string& prompt, std::string& input);

#endif
