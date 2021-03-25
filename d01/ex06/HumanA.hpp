/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 10:02:42 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:15:32 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon	&_weapon;
	public:
		HumanA(std::string const &init_name, Weapon& init_weapon);
		virtual ~HumanA();
		HumanA &operator=(HumanA const &rhs);
		void	attack();
};

#endif
