/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieEvent.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 22:39:59 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:11:32 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include <stdlib.h>

ZombieEvent::ZombieEvent()
{
	return ;
}

ZombieEvent::ZombieEvent(ZombieEvent const &src)
{
	*this = src;
}

ZombieEvent::~ZombieEvent()
{
	return ;
}

void	ZombieEvent::setZombieType(Zombie* zombie)
{
	zombie->setAttribute(TYPE, "A");
}

Zombie*	ZombieEvent::newZombie(std::string const &name)
{
	Zombie* zombie = new Zombie;
	setZombieType(zombie);
	zombie->setAttribute(NAME, name);
	return (zombie);
}

ZombieEvent &ZombieEvent::operator=(Zombie const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	ZombieEvent::randomChump()
{
	Zombie random;
	std::string names[4] = {
		"Paul",
		"Jerome",
		"Patricia",
		"Femke",
	};
	int	i = (rand() + 1) % 4;
	ZombieEvent::setZombieType(&random);
	random.setAttribute(NAME, names[i]);
	random.announce();
}
