/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombiehorde.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 23:19:34 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/17 16:56:18 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {
	private:
		Zombie	*_horde;
		int		_num;
		ZombieHorde();
	public:
		ZombieHorde(int n);
		ZombieHorde(Zombie const &src);
		ZombieHorde &operator=(ZombieHorde const & rhs);
		virtual ~ZombieHorde();
		void	announce();
		void	assignRandomName(Zombie *zombie);
};

#endif
