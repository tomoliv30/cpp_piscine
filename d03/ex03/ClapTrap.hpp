/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Claptrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 19:18:13 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:14:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

enum	e_attribute_type
{
	HIT_POINTS,
	MAX_HIT_POINTS,
	ENERGY_POINTS,
	MAX_ENERGY_POINTS,
	LEVEL,
	MELE_ATTACK_DAMAGE,
	RANGED_ATTACK_DAMAGE,
	ARMOR_DAMAGE_REDUCTION,
	NAME,
	TYPE
};

enum	e_attribute_value
{
	FRAGTRAP_HIT_POINTS = 100,
	FRAGTRAP_MAX_HIT_POINTS = 100,
	FRAGTRAP_ENERGY_POINTS = 100,
	FRAGTRAP_MAX_ENERGY_POINTS = 100,
	FRAGTRAP_LEVEL = 1,
	FRAGTRAP_MELE_ATTACK_DAMAGE = 30,
	FRAGTRAP_RANGED_ATTACK_DAMAGE = 20,
	FRAGTRAP_ARMOR_DAMAGE_REDUCTION = 5,
	FRAGTRAP_VAULT_MIN_EP = 25,
	SCAVTRAP_HIT_POINTS = 100,
	SCAVTRAP_MAX_HIT_POINTS = 100,
	SCAVTRAP_ENERGY_POINTS = 50,
	SCAVTRAP_MAX_ENERGY_POINTS = 50,
	SCAVTRAP_LEVEL = 1,
	SCAVTRAP_MELE_ATTACK_DAMAGE = 20,
	SCAVTRAP_RANGED_ATTACK_DAMAGE = 15,
	SCAVTRAP_ARMOR_DAMAGE_REDUCTION = 3,
	SCAVTRAP_CHALLENGE_NEWCOMER_MIN_EP = 20,
	NINJATRAP_HIT_POINTS = 60,
	NINJATRAP_MAX_HIT_POINTS = 60,
	NINJATRAP_ENERGY_POINTS = 120,
	NINJATRAP_MAX_ENERGY_POINTS = 120,
	NINJATRAP_LEVEL = 1,
	NINJATRAP_MELE_ATTACK_DAMAGE = 60,
	NINJATRAP_RANGED_ATTACK_DAMAGE = 5,
	NINJATRAP_ARMOR_DAMAGE_REDUCTION = 0,
	NINJATRAP_SHOEBOX_MIN_EP = 15,
	NINJATRAP_SHOEBOX_DAMAGE = 10
};

class	ClapTrap {
	protected:
		unsigned int 		_hitPoints;
		unsigned int 		_maxHitPoints;
		unsigned int 		_energyPoints;
		unsigned int 		_maxEnergyPoints;
		unsigned int 		_level;
		std::string			 _name;
		std::string			_type;
		unsigned int 		_meleeAttackDamage;
		unsigned int 		_rangedAttackDamage;
		unsigned int 		_armorDamageReduction;
		ClapTrap();
	public:
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & src);
		ClapTrap &operator=(ClapTrap const & rhs);
		virtual ~ClapTrap();
		void				displayStats();
		void				resetEnergy();
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				rangedAttack(std::string const & target);
		void				meleeAttack(std::string const & target);
		unsigned int		getAttributeUint(int type) const;
		std::string			getAttributeString(int type) const;
};

#endif
