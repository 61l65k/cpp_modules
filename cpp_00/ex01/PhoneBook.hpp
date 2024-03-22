/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:28:45 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/22 05:28:46 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int numcontacts;
    int oldestcontactindex;

public:
    PhoneBook();

    void    addContact(const Contact& contact);
    void    displayContacts() const;
    int     get_num_contacts() const;
    void    display_contact_info(int index) const;
};

#endif 
