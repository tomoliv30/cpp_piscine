/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 23:29:10 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:08:17 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <stdlib.h>

ZombieHorde::ZombieHorde() : _horde(NULL), _num(0)
{
	return ;
}

ZombieHorde::ZombieHorde(Zombie const &src)
{
	*this = src;
}

ZombieHorde::ZombieHorde(int n)
{
	if (n <= 0) {
		std::cerr << "nah" << std::endl; 
		this->_num = 0;
		this->_horde = NULL;
		return ;
	}
	this->_num = n;
	try
	{
		this->_horde = new Zombie[n];
		for (int i = 0; i < n; i++) {
			assignRandomName(&this->_horde[i]);
		}
	}
	catch (std::bad_alloc &e)
	{
		throw ;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete []_horde;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < this->_num; i++) {
		this->_horde[i].announce();
	}
}

void	ZombieHorde::assignRandomName(Zombie* zombie)
{
	std::string names[6] = {
		"Nemesis",
		"Leto", 
		"Artemis",
		"Demeter",
		"Orpheus",
		"Aphrodite",
	};
	int	i = rand() % 6;
	zombie->setAttribute(NAME, names[i]);
}

ZombieHorde &ZombieHorde::operator=(ZombieHorde const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}
