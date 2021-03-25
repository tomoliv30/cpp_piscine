/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:00:34 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 09:41:15 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	 main()
{
	std::string command;
	
	Phonebook phonebook;
	for (;;) {
	std::cout << ">" ;
	getline (std::cin, command);
	if (!std::cin || std::cin.eof()) {
		std::cout << "\nerror reading input, exiting..." << std::endl;
		return 1;
	}
	try
	{
		switch(phonebook.inputParser(command)) {
			case EXIT :
				return 0;
			case ADD:
				phonebook.addContact();
				break;
			case SEARCH:
				phonebook.showContact();
				phonebook.searchContact();
				break;
			case INVALID:
				if (command.length())
					std::cout << "Invalid command." << std::endl;
				break;
	}
	}
	catch(e_utils)
	{
		std::cout << "\nerror reading input, exiting..." << std::endl;
		return 1;
	}
	}
	return 0;
}
