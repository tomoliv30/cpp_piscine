/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pony.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:58:00 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:09:40 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string const & newName, int newLegs) : _name(newName), _legs(newLegs)
{
	std::cout << "Hi, I am " << _name << ", a Pony. I have " << _legs << " legs."<< std::endl;
}

Pony::~Pony()
{
	std::cout << "I'm about to die." << std::endl;
}

void	Pony::Bark()
{
	std::cout << "WOUF WOUF WOUF WOUF AHOUUU WOUF"  << std::endl;
}

void	Pony::Meow()
{
	std::cout << "MIAOU MIAOU MIAOU MIAOU MIAOU MIAOU FSSSHHH"  << std::endl;
}

Pony::Pony() : _name("default"), _legs(4)
{
	return ;
}

Pony::Pony(Pony const & src)
{
	this->_name = src.getName();
	this->_legs = src.getLegs();
}

Pony &Pony::operator=(Pony const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

int			Pony::getLegs() const
{
	return this->_legs;
}

std::string Pony::getName() const
{
	return this->_name;
}

