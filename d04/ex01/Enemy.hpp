/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Enemy.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:28:41 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 14:43:12 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy {
	private:
		std::string const _type;
		int _hp;
		Enemy();
	protected:
		void	setHP(int hp);
	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		Enemy &operator=(Enemy const &rhs);
		virtual ~Enemy();
		virtual void	takeDamage(int);
		std::string const & getType() const;
		int getHP() const;
};

#endif
