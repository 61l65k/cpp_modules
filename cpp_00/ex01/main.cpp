#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "handlers.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::cout << "Welcome to the Crappy Awesome Phonebook!" << std::endl;
    while (true)
    {
        if (get_valid_input("Enter a command (ADD, SEARCH, EXIT)> ", command) < 0) break;
        if (command == "ADD" && handle_add(phoneBook) < 0) break ;
        else if (command == "SEARCH")
        {
            handle_search(phoneBook);
        }
        else if (command == "EXIT")
        {
            handle_exit();
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}