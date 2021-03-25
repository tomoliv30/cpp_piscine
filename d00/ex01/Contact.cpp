/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:36:35 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/16 15:26:57 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

Contact::Contact(): _firstName("undefined"),
					_lastName("undefined"),
					_nickname("undefined"),
					_login("undefined"),
					_postalAddress("undefined"),
					_emailAddress("undefined"),
					_phoneNumber("undefined"),
					_birthdayDate("undefined"),
					_favoriteMeal("undefined"),
					_underwearColor("undefined"),
					_darkestSecret("undefined")
{
	return ;
}

Contact::Contact(Contact const & src) :
_firstName(src.getInfo(FIRST_NAME)),
_lastName(src.getInfo(LAST_NAME)),
_nickname(src.getInfo(NICKNAME)),
_login(src.getInfo(LOGIN)),
_postalAddress(src.getInfo(POSTAL_ADDRESS)),
_emailAddress(src.getInfo(EMAIL_ADDRESS)),
_phoneNumber(src.getInfo(PHONE_NUMBER)),
_birthdayDate(src.getInfo(BIRTHDAY_DATE)),
_favoriteMeal(src.getInfo(FAVORITE_MEAL)),
_underwearColor(src.getInfo(UNDERWEAR_COLOR)),
_darkestSecret(src.getInfo(DARKEST_SECRET))
{
	*this = src;
	return ;
}

Contact::Contact(std::string firstName, std::string lastName) :
_firstName(firstName),
_lastName(lastName),
_nickname("undefined"),
_login("undefined"),
_postalAddress("undefined"),
_emailAddress("undefined"),
_phoneNumber("undefined"),
_birthdayDate("undefined"),
_favoriteMeal("undefined"),
_underwearColor("undefined"),
_darkestSecret("undefined")
{
	return ;
}

Contact::~Contact()
{
	return ;
}

Contact &Contact::operator=(Contact const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string	Contact::getInfo(int type) const
{
	std::string invalid("");

	switch(type) {
		case FIRST_NAME:
			return this->_firstName;
		case LAST_NAME:
			return this->_lastName;
		case NICKNAME:
			return this->_nickname;
		case LOGIN:
			return this->_login;
		case POSTAL_ADDRESS:
			return this->_postalAddress;
		case EMAIL_ADDRESS:
			return this->_emailAddress;
		case PHONE_NUMBER:
			return this->_phoneNumber;
		case BIRTHDAY_DATE:
			return this->_birthdayDate;
		case FAVORITE_MEAL:
			return this->_favoriteMeal;
		case UNDERWEAR_COLOR:
			return this->_underwearColor;
		case DARKEST_SECRET:
			return this->_darkestSecret;
	}
	return (invalid);
}

void	Contact::setAttribute(int type, std::string prompt)
{
	std::cout << prompt << ":";
	switch(type) {
		case FIRST_NAME:
			getline(std::cin, _firstName);
			break ;
		case LAST_NAME:
			getline(std::cin, _lastName);
			break ;
		case NICKNAME:
			getline(std::cin, _nickname);
			break ;
		case LOGIN:
			getline(std::cin, _login);
			break ;
		case POSTAL_ADDRESS:
			getline(std::cin, _postalAddress);
			break ;
		case EMAIL_ADDRESS:
			getline(std::cin, _emailAddress);
			break ;
		case PHONE_NUMBER:
			getline(std::cin, _phoneNumber);
			break ;
		case BIRTHDAY_DATE:
			getline(std::cin, _birthdayDate);
			break ;
		case FAVORITE_MEAL:
			getline(std::cin, _favoriteMeal);
			break ;
		case UNDERWEAR_COLOR:
			getline(std::cin, _underwearColor);
			break ;
		case DARKEST_SECRET:
			getline(std::cin, _darkestSecret);
			break ;
	}
	if (!std::cin || std::cin.eof()) {
		throw (INTERRUPT);
	}
}
