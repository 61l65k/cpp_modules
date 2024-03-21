#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::cout << "Welcome to the Crappy Awesome Phonebook!" << std::endl;
    while (true)
    {
        std::cout << "\nEnter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter darkest secret: ";
            std::cin.ignore(); // Ignore newline character left by previous input
            std::getline(std::cin, darkestSecret);

            if (!firstName.empty() && !lastName.empty() && !nickname.empty() && !phoneNumber.empty() && !darkestSecret.empty())
                phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
            else
                std::cout << "All fields must be filled. Contact not added." << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "\nEnter the index of the contact to display: ";
            int index;
            std::cin >> index;
            if (std::cin.fail() || index < 1 || index > phoneBook.getNumContacts())
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << "Invalid index. Please try again." << std::endl;
            }
            else
            {
                phoneBook.displayContactInfo(index - 1);
            }
        } 

        else if (command == "EXIT")
        {
            std::cout << "Exiting phonebook. Goodbye!" << std::endl;
            break;
        }
        else
        std::cout << "Invalid command. Please try again." << std::endl;
    
    }
    return 0;
}
