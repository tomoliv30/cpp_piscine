/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SuperMutant.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:38:33 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 11:28:24 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : virtual public Enemy {
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		SuperMutant &operator=(SuperMutant const &rhs);
		virtual ~SuperMutant();
		virtual void	takeDamage(int damage);
};

#endif
