/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RadScorpion.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:42:22 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 11:28:40 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : virtual public Enemy {
	public:
		RadScorpion();
		RadScorpion(RadScorpion const & src);
		RadScorpion &operator=(RadScorpion const &rhs);
		virtual ~RadScorpion();
};

#endif
