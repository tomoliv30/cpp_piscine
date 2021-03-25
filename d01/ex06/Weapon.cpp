/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 17:19:16 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:17:26 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &init_type) 
{
	type = init_type;
}

const std::string &Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(std::string const &type) 
{
	this->type = type;
	return ;
}

Weapon::Weapon() : type("default")
{
	return ;
}

Weapon::Weapon(Weapon const &src)
{
	setType(src.getType());
}

Weapon::~Weapon()
{
	return ;
}

Weapon &Weapon::operator=(Weapon const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}
