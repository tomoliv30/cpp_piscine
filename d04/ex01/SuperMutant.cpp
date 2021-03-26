/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SuperMutant.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:41:13 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:53:48 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const & src) : Enemy(src)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return ;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs)
{
	this->setHP(rhs.getHP());
	return *this;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
	return ;
}

void	SuperMutant::takeDamage(int damage) 
{
	int	currentHp = getHP();

	if (damage <= 3)
		return ;
	if (!currentHp)
	{
		std::cout << "SuperMutant " << getType() << " cannot take more damage!" << std::endl;
		return ;
	}
	damage -= 3;
	if (damage > currentHp)
		damage = currentHp;
	setHP(currentHp - damage);
	std::cout << "SuperMutant " << getType() << " takes "  << damage << " points damage!" << std::endl;
}
