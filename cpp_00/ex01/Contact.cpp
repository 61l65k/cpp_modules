#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
                 const std::string& phoneNumber, const std::string& darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

void Contact::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Contact::set_nickname(const std::string& nickname)
{
    this->nickname = nickname;
}

void Contact::set_darkestsecret(const std::string& darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

void Contact::set_lastname(const std::string& lastName)
{
    this->lastName = lastName;
}

void Contact::set_phonenumber(const std::string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

std::string Contact::get_firstname() const
{
    return firstName;
}

std::string Contact::get_darkestsecret() const
{
    return darkestSecret;
}

std::string Contact::get_nickname() const
{
    return nickname;
}

std::string Contact::get_lastname() const
{
    return lastName;
}

std::string Contact::get_phonenumber() const
{
    return phoneNumber;
}
