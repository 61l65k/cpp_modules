/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 05:27:59 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/22 05:28:00 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
            const std::string& phoneNumber, const std::string& darkestSecret);

    void set_firstname(const std::string& firstName);
    void set_lastname(const std::string& lastName);
    void set_phonenumber(const std::string& phoneNumber);
    void set_nickname(const std::string& nickname);
    void set_darkestsecret(const std::string& darkestSecret);

    std::string get_darkestsecret() const;
    std::string get_firstname() const;
    std::string get_lastname() const;
    std::string get_phonenumber() const;
    std::string get_nickname() const;
};

#endif
