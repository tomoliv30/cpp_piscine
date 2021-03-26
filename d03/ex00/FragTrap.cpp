/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 17:30:19 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 10:58:25 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :
_hitPoints(FRAGTRAP_HIT_POINTS),
_maxHitPoints(FRAGTRAP_MAX_HIT_POINTS),
_energyPoints(FRAGTRAP_ENERGY_POINTS),
_maxEnergyPoints(FRAGTRAP_MAX_ENERGY_POINTS),
_level(FRAGTRAP_LEVEL),
_name("default"),
_type("FragTrap"),
_meleeAttackDamage(FRAGTRAP_MELE_ATTACK_DAMAGE),
_rangedAttackDamage(FRAGTRAP_RANGED_ATTACK_DAMAGE),
_armorDamageReduction(FRAGTRAP_ARMOR_DAMAGE_REDUCTION)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const & name) :
_hitPoints(FRAGTRAP_HIT_POINTS),
_maxHitPoints(FRAGTRAP_MAX_HIT_POINTS),
_energyPoints(FRAGTRAP_ENERGY_POINTS),
_maxEnergyPoints(FRAGTRAP_MAX_ENERGY_POINTS),
_level(FRAGTRAP_LEVEL),
_name(name),
_type("FragTrap"),
_meleeAttackDamage(FRAGTRAP_MELE_ATTACK_DAMAGE),
_rangedAttackDamage(FRAGTRAP_RANGED_ATTACK_DAMAGE),
_armorDamageReduction(FRAGTRAP_ARMOR_DAMAGE_REDUCTION)
{
	std::cout << "Parametric constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "Assignment constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const & rhs)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void		FragTrap::rangedAttack(std::string const & target)
{
	std::cout << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points damage!" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target)
{
	std::cout << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points damage!" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
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

void		FragTrap::beRepaired(unsigned int amount)
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

void		FragTrap::displayStats()
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

void		FragTrap::resetEnergy()
{
	this->_energyPoints = FRAGTRAP_MAX_ENERGY_POINTS;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energyPoints < FRAGTRAP_VAULT_MIN_EP) {
		std::cout << this->_name << " needs at least "<< FRAGTRAP_VAULT_MIN_EP << " energy points to perform this attack" << std::endl;
		return ;
	}
	std::cout << this->_name << " performs funny random attack " << rand() % 5 << " on " << target << std::endl;
	this->_energyPoints -= FRAGTRAP_VAULT_MIN_EP;
	std::cout << this->_name << " looses " << FRAGTRAP_VAULT_MIN_EP << " energy points." << std::endl;
}


std::string FragTrap::getAttributeString(int type) const
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

unsigned int		FragTrap::getAttributeUint(int type) const
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
