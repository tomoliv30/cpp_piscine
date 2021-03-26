/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 19:20:25 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:03:23 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_hitPoints(0),
_maxHitPoints(0),
_energyPoints(0),
_maxEnergyPoints(0),
_level(1),
_name("default"),
_type("ClapTrap"),
_meleeAttackDamage(0),
_rangedAttackDamage(0),
_armorDamageReduction(0)

{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}


ClapTrap::ClapTrap(std::string const & name) :
_hitPoints(0),
_maxHitPoints(0),
_energyPoints(0),
_maxEnergyPoints(0),
_level(1),
_name(name),
_type("ClapTrap"),
_meleeAttackDamage(0),
_rangedAttackDamage(0),
_armorDamageReduction(0)
{
	std::cout << "ClapTrap parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout  << "ClapTrap assignment constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & rhs)
{
	this->_hitPoints = rhs.getAttributeUint(HIT_POINTS);
	this->_maxHitPoints = rhs.getAttributeUint(MAX_HIT_POINTS);
	this->_energyPoints = rhs.getAttributeUint(ENERGY_POINTS);
	this->_maxEnergyPoints = rhs.getAttributeUint(MAX_ENERGY_POINTS);
	this->_level = rhs.getAttributeUint(LEVEL);
	this->_name = rhs.getAttributeString(NAME);
	this->_type = rhs.getAttributeString(TYPE);
	this->_meleeAttackDamage = rhs.getAttributeUint(MELE_ATTACK_DAMAGE);
	this->_rangedAttackDamage = rhs.getAttributeUint(RANGED_ATTACK_DAMAGE);
	this->_armorDamageReduction = rhs.getAttributeUint(ARMOR_DAMAGE_REDUCTION);
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << getAttributeString(NAME) <<std::endl;
	return ;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (!amount)
		return ;
	if (this->_hitPoints == this->_maxHitPoints) {
		std::cout << this->_name << " has reached max HP" << std::endl;
		return ;
	}
	if (this->_hitPoints + amount > this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_name << " is repaired by " << amount << " points" << std::endl;
}

void		ClapTrap::displayStats(void)
{
	std::cout << "\t\t\t|NAME: " << getAttributeString(NAME) << std::endl
			<< "\t\t\t|TYPE: " << getAttributeString(TYPE) << std::endl
		<< "\t\t\t|LEVEL: " << getAttributeUint(LEVEL) << std::endl
		<< "\t\t\t|HP: " << getAttributeUint(HIT_POINTS) << std::endl
		<< "\t\t\t|MAX HP: " << getAttributeUint(MAX_HIT_POINTS) << std::endl
		<< "\t\t\t|EP: " << getAttributeUint(ENERGY_POINTS) << std::endl
		<< "\t\t\t|MAX EP: " << getAttributeUint(MAX_ENERGY_POINTS) << std::endl
		<< "\t\t\t|MAD: " << getAttributeUint(MELE_ATTACK_DAMAGE) << std::endl
		<< "\t\t\t|RAD: " << getAttributeUint(RANGED_ATTACK_DAMAGE) << std::endl
		<< "\t\t\t|ADR: " << getAttributeUint(ARMOR_DAMAGE_REDUCTION) << std::endl;
}

void		ClapTrap::resetEnergy(void)
{
	this->_energyPoints = this->_maxEnergyPoints;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (!amount || amount == this->_armorDamageReduction)
		return ;
	if (!this->_hitPoints)
	{
		std::cout << this->_name << " cannot take more damage" << std::endl;
		return ;
	}
	if (this->_armorDamageReduction > amount)
		amount = 0;
	else
		amount -= this->_armorDamageReduction;
	if (amount > this->_hitPoints)
		amount = _hitPoints;
	this->_hitPoints -= amount;
	if (amount)
		std::cout << this->_name << " takes " << amount << " damage" << std::endl;
}

std::string ClapTrap::getAttributeString(int type) const
{
	switch (type)
	{
		case NAME:
			return this->_name;
		case TYPE:
			return this->_type;
	}
	return "";
}

unsigned int		ClapTrap::getAttributeUint(int type) const
{
	switch (type)
	{
		case HIT_POINTS:
			return this->_hitPoints;
		case MAX_HIT_POINTS:
			return this->_maxHitPoints;
		case ENERGY_POINTS:
			return this->_energyPoints;
		case MAX_ENERGY_POINTS:
			return this->_maxEnergyPoints;
		case LEVEL:
			return this->_level;
		case MELE_ATTACK_DAMAGE:
			return this->_meleeAttackDamage;
		case RANGED_ATTACK_DAMAGE:
			return this->_rangedAttackDamage;
		case ARMOR_DAMAGE_REDUCTION:
			return this->_armorDamageReduction;
	}
	return 0;
}

void				ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << getAttributeString(TYPE) << " named " << getAttributeString(NAME) << " performs meleeAttack on " << target << " causing " << getAttributeUint(MELE_ATTACK_DAMAGE) << " points damage!" << std::endl;
}

void				ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << getAttributeString(TYPE) << " named " << getAttributeString(NAME) << " performs ranged attack on " << target << " causing " << getAttributeUint(RANGED_ATTACK_DAMAGE) << " points damage!" << std::endl;
}
