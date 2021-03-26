/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dada.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:17:17 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:36:42 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dada.hpp"

Dada::Dada (std::string const & name) : Victim(name) {
	
	std::cout << "Dada " << name << " alive." << std::endl;
	return ;
}

Dada::Dada(Dada const & src) : Victim(src)
{
	std::cout << "Dada " << _name << " alive." << std::endl;
	return ;
}

Dada &Dada::operator=(Dada const &rhs)
{
	_name = rhs.getName();
	return *this;
}

Dada::~Dada() {
	std::cout << "Dada " << _name << " dead :( ..." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &output, Dada const &rhs){
	output << "I am " << rhs.getName() << ", a Dada." << std::endl;
	return (output);
}

void	Dada::getPolymorphed() const {
	std::cout << getName() << " has been turned into toilet paper!" << std::endl;
}
