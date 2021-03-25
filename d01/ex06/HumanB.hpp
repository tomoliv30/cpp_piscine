/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 10:02:53 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:16:12 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {

	private:
		std::string _name;
		Weapon 		*_weapon;
	public:
		HumanB(std::string const &init_name);
		HumanB &operator=(HumanB const &rhs);
		virtual ~HumanB();
		void	setWeapon(Weapon& new_weapon);
		void	attack();
};

#endif
