/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:54:22 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 09:44:58 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

enum		e_utils
{
	INTERRUPT = -1,
	EXIT = 0,
	ADD = 1,
	SEARCH = 2,
	INVALID = 3,
	COLUMN_WIDTH = 11,
};

class Phonebook {

	private:
		Contact 	_contacts[8];
		int			_n_contacts;
		std::string	_name;
	public:	
		Phonebook();
		Phonebook(std::string const name);
		Phonebook(Phonebook const &src);
		~Phonebook();
		Phonebook &operator=(Phonebook const &);
		void addContact();
		void showContact();
		void searchContact();
		void printEntry(std::string entry);
		void printIndex(int index);
		std::string truncateEntry(std::string entry);
		int	inputParser(std::string const &command);
};

#endif
