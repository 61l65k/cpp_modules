#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : numContacts(0) {}

void PhoneBook::addContact(const Contact& contact)
{
    if (numContacts < MAX_CONTACTS)
        contacts[numContacts++] = contact;
    else
        std::cout << "Phone book is full. Cannot add more contacts." << std::endl;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < numContacts; ++i) {
        std::string truncatedFirstName = contacts[i].getFirstName();
        std::string truncatedLastName = contacts[i].getLastName();
        std::string truncatedNickname = contacts[i].getNickname();

        // Truncate if longer than 10 characters
        if (truncatedFirstName.length() > 10) truncatedFirstName = truncatedFirstName.substr(0, 9) + ".";
        if (truncatedLastName.length() > 10) truncatedLastName = truncatedLastName.substr(0, 9) + ".";
        if (truncatedNickname.length() > 10) truncatedNickname = truncatedNickname.substr(0, 9) + ".";

        std::cout << std::setw(10) << (i + 1) << " | "
                  << std::setw(10) << std::right << truncatedFirstName << " | "
                  << std::setw(10) << std::right << truncatedLastName << " | "
                  << std::setw(10) << std::right << truncatedNickname << std::endl;
    }
}


int PhoneBook::getNumContacts() const
{
    return numContacts;
}

void PhoneBook::displayContactInfo(int index) const
{
    if (index >= 0 && index < numContacts)
    {
        std::cout << "Contact Info:" << std::endl;
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}
