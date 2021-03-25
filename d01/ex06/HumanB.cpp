/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 10:02:47 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:16:25 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const &init_name) 
{
	_name = init_name;
}

HumanB::~HumanB()
{
	return ;
}

HumanB &HumanB::operator=(HumanB const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	HumanB::setWeapon(Weapon& new_weapon) 
{
	_weapon = &new_weapon;
}

void	HumanB::attack() 
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}
