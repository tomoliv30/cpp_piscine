/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 17:30:19 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:15:02 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <stdlib.h>

FragTrap::FragTrap()
{
	this->_hitPoints = FRAGTRAP_HIT_POINTS;
	this->_maxHitPoints = FRAGTRAP_MAX_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = FRAGTRAP_MAX_ENERGY_POINTS;
	this->_level = FRAGTRAP_LEVEL;
	this->_name = "default";
	this->_type = "FragTrap";
	this->_meleeAttackDamage = FRAGTRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = FRAGTRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = FRAGTRAP_ARMOR_DAMAGE_REDUCTION;
	std::cout << getAttributeString(TYPE) << " default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const & name)
{
	this->_hitPoints = FRAGTRAP_HIT_POINTS;
	this->_maxHitPoints = FRAGTRAP_MAX_HIT_POINTS;
	this->_energyPoints = FRAGTRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = FRAGTRAP_MAX_ENERGY_POINTS;
	this->_level = FRAGTRAP_LEVEL;
	this->_name = name;
	this->_type = "FragTrap";
	this->_meleeAttackDamage = FRAGTRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = FRAGTRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = FRAGTRAP_ARMOR_DAMAGE_REDUCTION;
	std::cout << getAttributeString(TYPE) << " parametric constructor called with name " << getAttributeString(NAME) << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap Assignment constructor called" << std::endl;
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
	std::cout << "FragTrap destructor called for " << getAttributeString(NAME) << std::endl;
	return ;
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
