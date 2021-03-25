/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 10:03:28 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:17:30 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	private: 
		std::string type;
		Weapon();
	public:
		Weapon(std::string const &init_type);
		Weapon(Weapon const &src);
		~Weapon();
		Weapon &operator=(Weapon const &rhs);
		const std::string &getType() const;
		void	setType(std::string const &type);
};

#endif
