/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:58:31 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 09:44:49 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook() : _n_contacts(0),
						_name("crap")
{
	return ;
}

Phonebook::Phonebook(std::string const name) : _n_contacts(0),
												_name(name)
{
	return ;
}

Phonebook::Phonebook(Phonebook const &src)
{
	*this = src;
	return ;
}

Phonebook::~Phonebook()
{
	return ;
}

Phonebook &Phonebook::operator=(Phonebook const &)
{
	return *this;
}

std::string Phonebook::truncateEntry(std::string entry)
{
	if (entry.length() <= 10)
		return entry;
	std::string truncatedEntry = entry;
	truncatedEntry.resize(9);
	truncatedEntry.push_back('.');
	return truncatedEntry;
}

void Phonebook::addContact(void)
{
	if (_n_contacts == 8) {
		std::cout << "Too many contacts" << std::endl;
		return ;
	}
	_contacts[_n_contacts].setAttribute(FIRST_NAME, "first name");
	_contacts[_n_contacts].setAttribute(LAST_NAME, "last name");
	_contacts[_n_contacts].setAttribute(NICKNAME, "nickname");
	_contacts[_n_contacts].setAttribute(LOGIN, "login");
	_contacts[_n_contacts].setAttribute(POSTAL_ADDRESS, "postal address");
	_contacts[_n_contacts].setAttribute(EMAIL_ADDRESS, "email address");
	_contacts[_n_contacts].setAttribute(PHONE_NUMBER, "phone number");
	_contacts[_n_contacts].setAttribute(BIRTHDAY_DATE, "birthday date (ddmmyyyy)");
	_contacts[_n_contacts].setAttribute(FAVORITE_MEAL, "favorite meal");
	_contacts[_n_contacts].setAttribute(UNDERWEAR_COLOR, "underwear color");
	_contacts[_n_contacts].setAttribute(DARKEST_SECRET, "darkest secret");
	_n_contacts++;
}

void Phonebook::printEntry(std::string entry)
{
	std::cout << std::setw(COLUMN_WIDTH - 1) << truncateEntry(entry) << "|";
}

void Phonebook::printIndex(int index)
{
	std::cout << "|" << std::setw(COLUMN_WIDTH - 1) << index << "|";
}

void Phonebook::searchContact(void)
{
	std::string input;
	bool error = 0;
	int	index;
	if (!_n_contacts)
		return ;
	for (;;) {
		if (!error) 
			std::cout<< "enter contact index:";
		else
			std::cout<< "please enter a valid index:";
		error = 0;
		getline(std::cin, input);
		if (!std::cin || std::cin.eof()) {
			throw(INTERRUPT);
		}
		index = atoi(input.c_str());
		if (input.length() == 1 
				&& isdigit(input.at(0)) 
				&& index >= 0 
				&& index < _n_contacts){
			std::cout << "first name: ";
			std::cout << _contacts[index].getInfo(FIRST_NAME) << std::endl;
			std::cout << "last name: ";
			std::cout << _contacts[index].getInfo(LAST_NAME) << std::endl;
			std::cout << "nickname: ";
			std::cout << _contacts[index].getInfo(NICKNAME) << std::endl;
			std::cout << "login: ";
			std::cout << _contacts[index].getInfo(LOGIN) << std::endl;
			std::cout << "postal address: ";
			std::cout << _contacts[index].getInfo(POSTAL_ADDRESS) << std::endl;
			std::cout << "email address: ";
			std::cout << _contacts[index].getInfo(EMAIL_ADDRESS) << std::endl;
			std::cout << "phone number: ";
			std::cout << _contacts[index].getInfo(PHONE_NUMBER) << std::endl;
			std::cout << "birthday date (ddmmyyyy): ";
			std::cout << _contacts[index].getInfo(BIRTHDAY_DATE) << std::endl;
			std::cout << "favorite meal: ";
			std::cout << _contacts[index].getInfo(FAVORITE_MEAL) << std::endl;
			std::cout << "underwear color: ";
			std::cout << _contacts[index].getInfo(UNDERWEAR_COLOR) << std::endl;
			std::cout << "darkest secret: ";
			std::cout << _contacts[index].getInfo(DARKEST_SECRET) << std::endl;
			return ;
		}
		else
			error = 1;
	}
}

void Phonebook::showContact(void)
{
	if (!_n_contacts) {
		std::cout << "No contacts to show." << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(COLUMN_WIDTH) << "index|" 
						<< std::setw(COLUMN_WIDTH) << "first name|"
						<< std::setw(COLUMN_WIDTH) << "last name|" 
						<< std::setw(COLUMN_WIDTH) << "nickname|" 
						<< std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for	(int i = 0; i < _n_contacts; i++) { 
		printIndex(i);
		printEntry(_contacts[i].getInfo(FIRST_NAME));
		printEntry(_contacts[i].getInfo(LAST_NAME));
		printEntry(_contacts[i].getInfo(NICKNAME));
		std::cout << "\n---------------------------------------------" << std::endl;
	}
}

int	Phonebook::inputParser(std::string const &command)
{
    if (command == "EXIT") return EXIT;
    if (command == "ADD") return ADD;
    if (command == "SEARCH") return SEARCH;
	return INVALID;
}
