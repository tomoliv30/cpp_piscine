/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 17:27:35 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 10:59:01 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

enum	e_attribute
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

enum	e_fragtrap_attribute_value
{
	FRAGTRAP_HIT_POINTS = 100,
	FRAGTRAP_MAX_HIT_POINTS = 100,
	FRAGTRAP_ENERGY_POINTS = 100,
	FRAGTRAP_MAX_ENERGY_POINTS = 100,
	FRAGTRAP_LEVEL = 1,
	FRAGTRAP_MELE_ATTACK_DAMAGE = 30,
	FRAGTRAP_RANGED_ATTACK_DAMAGE = 20,
	FRAGTRAP_ARMOR_DAMAGE_REDUCTION = 5,
	FRAGTRAP_VAULT_MIN_EP = 25
};

class	FragTrap {
	private:
		unsigned int 		_hitPoints;
		unsigned int 		_maxHitPoints;
		unsigned int 		_energyPoints;
		unsigned int 		_maxEnergyPoints;
		unsigned int 		_level;
		std::string 		_name;
		std::string 		_type;
		unsigned int 		_meleeAttackDamage;
		unsigned int 		_rangedAttackDamage;
		unsigned int 		_armorDamageReduction;
		FragTrap();
	public:
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		FragTrap &operator=(FragTrap const & rhs);
		virtual ~FragTrap();
		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		displayStats();
		void		resetEnergy();
		void		vaulthunter_dot_exe(std::string const & target);
		unsigned int		getAttributeUint(int type) const;
		std::string getAttributeString(int type) const;
};

#endif
