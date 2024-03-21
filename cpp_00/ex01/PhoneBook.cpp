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

static std::string truncate(const std::string& str, int width)
{
    if (str.length() > (size_t)width)
        return (str.substr(0, width - 1) + ".");
    return (str);
}

void PhoneBook::displayContacts() const
{
    const int width = 10;
    const char separator = '|';
    const std::string border = "+----------+----------+----------+----------+";

    std::cout   << border << std::endl;
    std::cout   << separator << std::setw(width) << std::right << "Index" << separator
                << std::setw(width) << "First Name" << separator
                << std::setw(width) << "Last Name" << separator
                << std::setw(width) << "Nickname" << separator << std::endl;
    std::cout << border << std::endl;

    for (int i = 0; i < numContacts; ++i)
    {
        std::cout << separator << std::setw(width) << (i + 1) << separator
                  << std::setw(width) << truncate(contacts[i].get_firstname(), width) << separator
                  << std::setw(width) << truncate(contacts[i].get_lastname(), width) << separator
                  << std::setw(width) << truncate(contacts[i].get_nickname(), width) << separator << std::endl;
    }

    std::cout << border << std::endl;
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
        std::cout << "First Name: " << contacts[index].get_firstname() << std::endl;
        std::cout << "Last Name: " << contacts[index].get_lastname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].get_phonenumber() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}
