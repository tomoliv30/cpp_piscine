/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   NinjaTrap.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:24:54 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:04:11 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	this->_hitPoints = NINJATRAP_HIT_POINTS;
	this->_maxHitPoints = NINJATRAP_MAX_HIT_POINTS;
	this->_energyPoints = NINJATRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = NINJATRAP_MAX_ENERGY_POINTS;
	this->_level = NINJATRAP_LEVEL;
	this->_name = "default";
	this->_type = "NinjaTrap";
	this->_meleeAttackDamage = NINJATRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = NINJATRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = NINJATRAP_ARMOR_DAMAGE_REDUCTION;
	std::cout << getAttributeString(TYPE) << " default constructor called" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	std::cout << "NinjaTrap assignment constructor called for " << getAttributeString(NAME) << std::endl;
	*this = src;
	return ;
}

NinjaTrap::NinjaTrap(std::string const & name)
{
	this->_hitPoints = NINJATRAP_HIT_POINTS;
	this->_maxHitPoints = NINJATRAP_MAX_HIT_POINTS;
	this->_energyPoints = NINJATRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = NINJATRAP_MAX_ENERGY_POINTS;
	this->_level = NINJATRAP_LEVEL;
	this->_name = name;
	this->_type = "NinjaTrap";
	this->_meleeAttackDamage = NINJATRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = NINJATRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = NINJATRAP_ARMOR_DAMAGE_REDUCTION;
	std::cout << this->_type << " parametric constructor called for " << this->_name << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap destructor called for " << getAttributeString(NAME) << std::endl;
	return ;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const & rhs)
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
	return (*this);
}

void 		NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	if (this->_energyPoints < NINJATRAP_SHOEBOX_MIN_EP) {
		std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " needs at least " << NINJATRAP_SHOEBOX_MIN_EP << " energy points to perform this attack, currently has " << getAttributeUint(ENERGY_POINTS) << std::endl;
		return ;
	}
	std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " throws a shoe in ClapTrap " << target.getAttributeString(NAME) << "'s face, causing " << NINJATRAP_SHOEBOX_DAMAGE << " points damage!" << std::endl;
	this->_energyPoints -= NINJATRAP_SHOEBOX_MIN_EP;
	std::cout << this->_name << " looses " << NINJATRAP_SHOEBOX_MIN_EP << " energy points." << std::endl;
	target.takeDamage(NINJATRAP_SHOEBOX_DAMAGE);
}

void 		NinjaTrap::ninjaShoebox(FragTrap &target)
{
	if (this->_energyPoints < NINJATRAP_SHOEBOX_MIN_EP) {
		std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " needs at least " << NINJATRAP_SHOEBOX_MIN_EP << " energy points to perform this attack, currently has " << getAttributeUint(ENERGY_POINTS) << std::endl;
		return ;
	}
	std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " throws a shoe in " << target.getAttributeString(TYPE) << " " << target.getAttributeString(NAME) << "'s face, causing " << NINJATRAP_SHOEBOX_DAMAGE << " points damage!" << std::endl;
	this->_energyPoints -= NINJATRAP_SHOEBOX_MIN_EP;
	std::cout << this->_name << " looses " << NINJATRAP_SHOEBOX_MIN_EP << " energy points." << std::endl;
	target.takeDamage(NINJATRAP_SHOEBOX_DAMAGE);
}

void 		NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	if (this->_energyPoints < NINJATRAP_SHOEBOX_MIN_EP) {
		std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " needs at least " << NINJATRAP_SHOEBOX_MIN_EP << " energy points to perform this attack, currently has " << getAttributeUint(ENERGY_POINTS) << std::endl;
		return ;
	}
	std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " throws a shoe in " << target.getAttributeString(TYPE) << " " << target.getAttributeString(NAME) << "'s face, causing " << NINJATRAP_SHOEBOX_DAMAGE << " points damage!" << std::endl;
	this->_energyPoints -= NINJATRAP_SHOEBOX_MIN_EP;
	std::cout << this->_name << " looses " << NINJATRAP_SHOEBOX_MIN_EP << " energy points." << std::endl;
	target.takeDamage(NINJATRAP_SHOEBOX_DAMAGE);
}

void 		NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	if (this->_energyPoints < NINJATRAP_SHOEBOX_MIN_EP) {
		std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " needs at least " << NINJATRAP_SHOEBOX_MIN_EP << " energy points to perform this attack, currently has " << getAttributeUint(ENERGY_POINTS) << std::endl;
		return ;
	}
	std::cout << getAttributeString(TYPE) << " " << getAttributeString(NAME) << " throws a shoe in " << target.getAttributeString(TYPE) << " " << target.getAttributeString(NAME) << "'s face, causing " << NINJATRAP_SHOEBOX_DAMAGE << " points damage!" << std::endl;
	this->_energyPoints -= NINJATRAP_SHOEBOX_MIN_EP;
	std::cout << this->_name << " looses " << NINJATRAP_SHOEBOX_MIN_EP << " energy points." << std::endl;
	target.takeDamage(NINJATRAP_SHOEBOX_DAMAGE);
}
