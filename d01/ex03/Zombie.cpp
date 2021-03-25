/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 18:08:41 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:12:51 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("undefined"), _type("undefined")
{
	return ;
}

Zombie::Zombie(Zombie const &src)
{
	_name = src._name;
	_type = src._type;
}

Zombie::Zombie(std::string const &name, std::string const &type) : _name(name), _type(type)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << _name << "(" << _type << ") is about to die." << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << " (" << _type << ") Braiiiiiiiins ......." << std::endl;
}

Zombie &Zombie::operator=(Zombie const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	Zombie::setAttribute(e_attribute attribute, std::string const &value)
{
	switch(attribute) {
		case NAME:
			this->_name = value;
			break ;
		case TYPE:
			this->_type = value;
			break ;
	}
}

std::string	Zombie::getAttribute(e_attribute attribute) const
{
	switch(attribute) {
		case NAME:
			return this->_name;
		case TYPE:
			return this->_type;
	}
}


