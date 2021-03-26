/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:43:29 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:39:16 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() :
	_name("default"),
	_ap(40),
	_weapon(NULL)
{
	return ;
}

Character::Character(std::string const & name) :
	_name(name),
	_ap(40),
	_weapon(NULL)
{
	return ;
}

Character::Character(Character const & src)
{
	*this = src;
	return ;
}

Character &Character::operator=(Character const &rhs)
{
	this->_weapon = rhs._weapon;
	this->_ap= rhs._ap;
	return *this;
}

Character::~Character() 
{
	return ;
}

void	Character::recoverAP() 
{
	int	currentAP = getAP();

	if (currentAP == 40) {
		std::cout << "Max AP reached." << std::endl;
		return ;
	}
	int newAP = 40 - currentAP;
	newAP = newAP > 10 ? 10 : newAP;
	this->_ap += newAP;
	std::cout << _name << "recovers " << newAP << " ap points." << std::endl;
	return ;
}

void	Character::equip(AWeapon *weapon) 
{
	if (weapon)
		this->_weapon = weapon;
	return ;
}

void	Character::attack(Enemy *enemy) 
{
	if (!enemy)
		return ;
	if (!this->_weapon)
	{
		std::cout << "Character " << _name << " doesn't have a weapon!" << std::endl;
		return ;
	}
	if (this->_weapon->getAttribute(AP_COST) > this->_ap)
	{
		std::cout << "Character " << _name << " doesn't have enough action points!" << std::endl;
		return ;
	}
	std::cout << getName() << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	this->_ap -= this->_weapon->getAttribute(AP_COST);
	enemy->takeDamage(this->_weapon->getAttribute(DAMAGE));
	if (!(enemy->getHP()))
		delete enemy;
	return ;
}

std::string const & Character::getName() const 
{
	return this->_name;
}

unsigned int Character::getAP() const
{
	return this->_ap;
}

AWeapon	*Character::getWeapon() const 
{
	return this->_weapon;
}

std::ostream &operator<<(std::ostream &output, Character const &rhs)
{
	output << rhs.getName() << " has " << rhs.getAP() << " AP";
	if (rhs.getWeapon())
		output << " and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		output << " and is unarmed" << std::endl;
	return (output);
}
