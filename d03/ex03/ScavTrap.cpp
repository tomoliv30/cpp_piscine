/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 18:53:36 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:15:17 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <stdlib.h>

ScavTrap::ScavTrap()
{
	this->_hitPoints = SCAVTRAP_HIT_POINTS;
	this->_maxHitPoints = SCAVTRAP_MAX_HIT_POINTS;
	this->_energyPoints = SCAVTRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = SCAVTRAP_MAX_ENERGY_POINTS;
	this->_level = SCAVTRAP_LEVEL;
	this->_name = "default";
	this->_type = "ScavTrap";
	this->_meleeAttackDamage = SCAVTRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = SCAVTRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = SCAVTRAP_ARMOR_DAMAGE_REDUCTION;
	std::cout << getAttributeString(TYPE) << " default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const & name)
{
	this->_hitPoints = SCAVTRAP_HIT_POINTS;
	this->_maxHitPoints = SCAVTRAP_MAX_HIT_POINTS;
	this->_energyPoints = SCAVTRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = SCAVTRAP_MAX_ENERGY_POINTS;
	this->_level = SCAVTRAP_LEVEL;
	this->_name = name;
	this->_type = "ScavTrap";
	this->_meleeAttackDamage = SCAVTRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = SCAVTRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = SCAVTRAP_ARMOR_DAMAGE_REDUCTION;
	std::cout << getAttributeString(TYPE) << " parametric constructor called with name " << getAttributeString(NAME) << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "ScavTrap Assignment constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
{
	this->_hitPoints = rhs.getAttributeUint(HIT_POINTS);
	this->_maxHitPoints = rhs.getAttributeUint(MAX_HIT_POINTS);
	this->_energyPoints = rhs.getAttributeUint(ENERGY_POINTS);
	this->_maxEnergyPoints= rhs.getAttributeUint(MAX_ENERGY_POINTS);
	this->_level= rhs.getAttributeUint(LEVEL);
	this->_name = rhs.getAttributeString(NAME);
	this->_type = rhs.getAttributeString(TYPE);
	this->_meleeAttackDamage= rhs.getAttributeUint(MELE_ATTACK_DAMAGE);
	this->_rangedAttackDamage= rhs.getAttributeUint(RANGED_ATTACK_DAMAGE);
	this->_armorDamageReduction= rhs.getAttributeUint(ARMOR_DAMAGE_REDUCTION);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << getAttributeString(TYPE) << " destructor called for " << getAttributeString(NAME) << std::endl;
	return ;
}

void	ScavTrap::challengeNewcomer(std::string const &target)
{
	if (this->_energyPoints < SCAVTRAP_CHALLENGE_NEWCOMER_MIN_EP) {
		std::cout << this->_name << " needs at least " << SCAVTRAP_CHALLENGE_NEWCOMER_MIN_EP << " energy points to perform this attack" << std::endl;
		return ;
	}
	std:: cout << "I challenge " << target << " with funny challenge " << rand() % 5 << "!" << std::endl;
	this->_energyPoints -= SCAVTRAP_CHALLENGE_NEWCOMER_MIN_EP;
	std::cout << this->_name << " looses " << SCAVTRAP_CHALLENGE_NEWCOMER_MIN_EP << " energy points." << std::endl;
}
