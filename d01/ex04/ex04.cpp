/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex04.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 08:45:00 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:13:30 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {

	std::string brain = "HI THIS IS BRAIN";
	std::string	*pointer = &brain;
	std::string	&reference = brain;
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;

	std::cout << "Changing value of reference.." << std::endl;
	reference = "BRAIN IS HI THIS";
	std::cout << brain << std::endl;
	std::cout << *pointer << std::endl;

	std::cout << "Resetting value of original string.." << std::endl;
	brain = "HI THIS IS BRAIN";
	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;

	std::cout << "Changing value of value referenced by the pointer" << std::endl;
	*pointer = "BRAIN IS HI THIS";
	std::cout << brain << std::endl;
	std::cout << reference << std::endl;
	return (0);
}
