/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SuperTrap.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:58:26 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:10:13 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
	this->_hitPoints = SUPERTRAP_HIT_POINTS;
	this->_maxHitPoints = SUPERTRAP_MAX_HIT_POINTS;
	this->_energyPoints = SUPERTRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = SUPERTRAP_MAX_ENERGY_POINTS;
	this->_name = "default";
	this->_meleeAttackDamage = SUPERTRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = SUPERTRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = SUPERTRAP_ARMOR_DAMAGE_REDUCTION;
	this->_type = "SuperTrap";
	std::cout << "SuperTrap default constructor called" << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string const & name)
{
	this->_hitPoints = SUPERTRAP_HIT_POINTS;
	this->_maxHitPoints = SUPERTRAP_MAX_HIT_POINTS;
	this->_energyPoints = SUPERTRAP_ENERGY_POINTS;
	this->_maxEnergyPoints = SUPERTRAP_MAX_ENERGY_POINTS;
	this->_name = name;
	this->_meleeAttackDamage = SUPERTRAP_MELE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = SUPERTRAP_RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = SUPERTRAP_ARMOR_DAMAGE_REDUCTION;
	this->_type = "SuperTrap";
	std::cout << "SuperTrap parametric constructor called for " << this->_name << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	std::cout << "SuperTrap assignment constructor called for " << getAttributeString(NAME) << std::endl;
	*this = src;
	return ;
}

SuperTrap &SuperTrap::operator=(const SuperTrap &rhs)
{
    this->_hitPoints = rhs._hitPoints;
    this->_maxHitPoints = rhs._maxHitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_maxEnergyPoints = rhs._maxEnergyPoints;
    this->_level = rhs._level;
    this->_name = rhs._name;
    this->_meleeAttackDamage = rhs._meleeAttackDamage;
    this->_rangedAttackDamage = rhs._rangedAttackDamage;
    this->_armorDamageReduction = rhs._armorDamageReduction;
	return (*this);
}

SuperTrap::~SuperTrap() {
	std::cout << "SuperTrap destructor called for " << getAttributeString(NAME) << std::endl;
	return ;
}

void          SuperTrap::rangedAttack(std::string const &target) {
	return (FragTrap::rangedAttack(target));
}

void          SuperTrap::meleeAttack(std::string const &target) {
	return (NinjaTrap::meleeAttack(target));
}
