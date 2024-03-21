#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
                 const std::string& phoneNumber, const std::string& darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

void Contact::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Contact::setNickName(const std::string& nickname)
{
    this->nickname = nickname;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    this->darkestSecret = darkestSecret;
}


void Contact::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}
