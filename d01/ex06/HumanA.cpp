/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 10:02:31 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:16:03 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const &init_name, Weapon& init_weapon) : _weapon(init_weapon) 
{
		_name = init_name;
}

HumanA::~HumanA()
{
	return ;
}

HumanA &HumanA::operator=(HumanA const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	HumanA::attack() 
{
		std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
