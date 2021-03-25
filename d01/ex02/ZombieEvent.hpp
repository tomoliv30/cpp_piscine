/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieEvent.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 18:07:14 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:11:30 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"

class ZombieEvent {

	public:
		ZombieEvent();
		ZombieEvent(ZombieEvent const &src);
		ZombieEvent &operator=(Zombie const & rhs);
		virtual ~ZombieEvent();
		void	setZombieType(Zombie* zombie);
		Zombie*	newZombie(std::string const &name);
		void	randomChump();
};

#endif
