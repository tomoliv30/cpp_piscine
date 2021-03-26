/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AWeapon.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:15:11 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:31:57 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() :
	_name("default"),
	_damage(0),
	_apcost(0)
{
	return ;
}

AWeapon::AWeapon(std::string const & name, unsigned int apcost, unsigned int damage) :
	_name(name),
	_damage(damage),
	_apcost(apcost)
{
	return ;
}

AWeapon::AWeapon(AWeapon const & src){
	*this = src;
}

AWeapon::~AWeapon() {
	return ;
}

std::string  const & AWeapon::getName() const {
	return this->_name;
}

unsigned int	AWeapon::getAttribute(int type) const {
	switch (type)
	{
		case DAMAGE:
			return _damage;
		case AP_COST:
			return _apcost;
	}
	return 0;
}

AWeapon &AWeapon::operator=(AWeapon const &rhs)
{
	this->_damage = rhs._damage;
	this->_apcost = rhs._apcost;
	return *this;
}

void	AWeapon::setAttributes(unsigned int damage, unsigned int apcost)
{
	this->_damage = damage;
	this->_apcost = apcost;
}

void	AWeapon::attack() const
{
}
