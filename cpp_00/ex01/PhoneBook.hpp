#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int numContacts;

public:
    PhoneBook();

    void addContact(const Contact& contact);
    void displayContacts() const;
    int getNumContacts() const;
    void displayContactInfo(int index) const;
};

#endif 