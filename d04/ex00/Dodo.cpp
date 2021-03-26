/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dodo.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:17:17 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:37:31 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dodo.hpp"

Dodo::Dodo (std::string const & name) : Victim(name) {
	
	std::cout << "Dodo " << name << " alive." << std::endl;
	return ;
}

Dodo::Dodo(Dodo const & src) : Victim(src)
{
	std::cout << "Dodo " << _name << " alive." << std::endl;
	return ;
}

Dodo::~Dodo(void) {
	std::cout << "Dodo " << _name << " dead :( ..." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &output, Dodo const & rhs){
	output << "I am " << rhs.getName() << ", a Dodo." << std::endl;
	return (output);
}

void	Dodo::getPolymorphed() const {
	std::cout << getName() << " has been turned into a rotten fruit!" << std::endl;
}

Dodo &Dodo::operator=(Dodo const & rhs)
{
	_name = rhs.getName();
	return *this;
}
