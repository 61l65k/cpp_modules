/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:28:34 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/22 05:28:36 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : numcontacts(0), oldestcontactindex(0){}

void PhoneBook::addContact(const Contact& contact)
{
    if (numcontacts < MAX_CONTACTS)
        contacts[numcontacts++] = contact;
    else
    {
        contacts[oldestcontactindex] = contact;
        oldestcontactindex = (oldestcontactindex + 1) % MAX_CONTACTS;
    }
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

    for (int i = 0; i < numcontacts; ++i)
    {
        std::cout << separator << std::setw(width) << (i + 1) << separator
                  << std::setw(width) << truncate(contacts[i].get_firstname(), width) << separator
                  << std::setw(width) << truncate(contacts[i].get_lastname(), width) << separator
                  << std::setw(width) << truncate(contacts[i].get_nickname(), width) << separator << std::endl;
    }
    std::cout << border << std::endl;
}

int PhoneBook::get_num_contacts() const
{
    return numcontacts;
}

void PhoneBook::display_contact_info(int index) const
{
    if (index >= 0 && index < numcontacts)
    {
        std::cout << "Contact Info:" << std::endl;
        std::cout << "First Name: " << contacts[index].get_firstname() << std::endl;
        std::cout << "Last Name: " << contacts[index].get_lastname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].get_phonenumber() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}
