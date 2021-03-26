/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Peon.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:17:17 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:38:10 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon (std::string const & name) : Victim(name) {
	
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(Peon const & src) : Victim(src)
{
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &output, Peon const &rhs){
	output << "I am " << rhs.getName() << ", and I like otters!" << std::endl;
	return (output);
}

void	Peon::getPolymorphed() const {
	std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}

Peon &Peon::operator=(Peon const &rhs)
{
	_name = rhs.getName();
	return *this;
}
