/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AssaultTerminator.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:12:30 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:45:55 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	*this = src;
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &)
{
	return (*this);
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator *AssaultTerminator::clone(void) const {
	return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with a chainsfists *" << std::endl;

}
