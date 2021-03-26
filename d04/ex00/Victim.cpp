/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Victim.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:21:08 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:40:43 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim () :
	_name("undefined")
{
	return ;
}

Victim::Victim (std::string const & name)  :
	_name(name)
{
	std::cout << "Some random victim called " << getName() << " just appeared!" << std::endl;
	return ;
}

Victim::Victim(Victim const & src) {
	*this = src;
	std::cout << "Some random victim called " << getName() << " just appeared!" << std::endl;
	return ;
}

Victim &Victim::operator=(Victim const & rhs)
{
	_name = rhs.getName();
	return *this;
}

Victim::~Victim() {
	std::cout << "Victim "<< getName() << " just died for no apparent reason!" << std::endl;
	return ;
}

std::string const & Victim::getName() const {
	return this->_name;
}

std::ostream &operator<<(std::ostream &output, Victim const &rhs){
	output << "I am " << rhs.getName() << ", and I like otters!" << std::endl;
	return (output);
}

void	Victim::getPolymorphed() const {
	std::cout << getName() << " has been turned into a cute little sheep!" << std::endl;
}
