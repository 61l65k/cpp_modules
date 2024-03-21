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
                return -1;
            }
        }
    } while (input.find_first_not_of(' ') == std::string::npos);
    return 0;
}

int handle_add(PhoneBook& phoneBook)
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    if (get_valid_input("Enter first name: ", firstName) == -1) return -1;
    if (get_valid_input("Enter last name: ", lastName) == -1) return -1;
    if (get_valid_input("Enter nickname: ", nickname) == -1) return -1;
    if (get_valid_input("Enter phone number: ", phoneNumber) == -1) return -1;
    if (get_valid_input("Enter darkest secret: ", darkestSecret) == -1) return -1;
    phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
    return 0;
}

void handle_search(PhoneBook& phoneBook)
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

void handle_exit()
{
    std::cout << "Exiting phonebook. Goodbye!" << std::endl;
}
