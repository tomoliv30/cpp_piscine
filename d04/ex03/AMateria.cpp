/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 12:37:46 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:47:53 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _xp(0), _type("default"), _name("default")
{
}

AMateria::AMateria(std::string const & type) : _xp(0), _type(type), _name("default")
{
}

AMateria::AMateria(std::string const & type, std::string const & name) : _xp(0), _type(type), _name(name)
{
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	return ;
}

AMateria::~AMateria()
{
	return ;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

AMateria &AMateria::operator=(AMateria const & rhs)
{
	this->_xp = rhs._xp;
	this->_name = rhs._name;
	return (*this);
}

void AMateria::use(ICharacter&)
{
	updateXP();
}

void	AMateria::updateXP()
{
	unsigned int addXp = _maxXp - _xp;

	if (_xp == _maxXp) {
		std::cout << "max xp reached." << std::endl;
		return ;
	}
	addXp = addXp < 10 ? addXp : 10;
	_xp += addXp;
}

void	AMateria::displayStats()
{
	std::cout << "name: " << _name << " type: " << _type << " xp: " << _xp << std::endl;
}
