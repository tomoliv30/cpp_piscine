/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 18:53:22 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 10:59:29 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "FragTrap.hpp"

enum	e_scavtrap_attribute_value
{
	SCAVTRAP_HIT_POINTS = 100,
	SCAVTRAP_MAX_HIT_POINTS = 100,
	SCAVTRAP_ENERGY_POINTS = 50,
	SCAVTRAP_MAX_ENERGY_POINTS = 50,
	SCAVTRAP_LEVEL = 1,
	SCAVTRAP_MELE_ATTACK_DAMAGE = 20,
	SCAVTRAP_RANGED_ATTACK_DAMAGE = 15,
	SCAVTRAP_ARMOR_DAMAGE_REDUCTION = 3,
	SCAVTRAP_CHALLENGE_NEWCOMER_MIN_EP = 20
};

class	ScavTrap 
{
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
		ScavTrap();
	public:
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		ScavTrap &operator=(ScavTrap const & rhs);
		virtual ~ScavTrap();
		void		displayStats();
		void		resetEnergy();
		void		rangedAttack(std::string const & target);
		void		meleeAttack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const &target);
		unsigned int		getAttributeUint(int type) const;
		std::string 		getAttributeString(int type) const;
};

#endif
