/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:28:06 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/22 05:28:07 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.hpp"

int get_valid_input(const std::string& prompt, std::string& input)
{
    do {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            if (std::cin.eof())
            {
                std::cout << "\nEOF detected. Exiting phonebook. Goodbye!" << std::endl;
                return ERROR;
            }
        }
    } while (input.find_first_not_of(' ') == std::string::npos);
    return SUCCESS;
}

int handle_add(PhoneBook& phoneBook)
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    if (get_valid_input("Enter first name: ", firstName) == ERROR) return ERROR;
    if (get_valid_input("Enter last name: ", lastName) == ERROR) return ERROR;
    if (get_valid_input("Enter nickname: ", nickname) == ERROR) return ERROR;
    if (get_valid_input("Enter phone number: ", phoneNumber) == ERROR) return ERROR;
    if (get_valid_input("Enter darkest secret: ", darkestSecret) == ERROR) return ERROR;
    phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
    return SUCCESS;
}

void handle_search(PhoneBook& phoneBook)
{
    phoneBook.displayContacts();
    std::cout << "\nEnter the index of the contact to display: ";
    int index;
    std::cin >> index;
    if (std::cin.fail() || index < 1 || index > phoneBook.get_num_contacts())
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << "Invalid index. Please try again." << std::endl;
    }
    else
    {
        phoneBook.display_contact_info(index - 1);
    }
}

void handle_exit()
{
    std::cout << "Exiting phonebook. Goodbye!" << std::endl;
}
