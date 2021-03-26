/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:43:24 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 16:41:51 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {
	private:
		std::string const _name;
		unsigned int _ap;
		AWeapon		*_weapon;
		Character();
	public:
		Character(std::string const & name);
		Character(Character const & src);
		Character &operator=(Character const &rhs);
		~Character();
		void	recoverAP();
		void	equip(AWeapon *weapon);
		void	attack(Enemy *enemy);
		std::string const  & getName() const;
		unsigned int getAP() const;
		AWeapon *getWeapon() const;
};

std::ostream &operator<<(std::ostream &output, Character const &rhs);

#endif
