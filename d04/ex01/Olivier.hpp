/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Olivier.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:13:52 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:10:36 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OLIVIER_HPP
# define OLIVIER_HPP

# include "Enemy.hpp"

class Olivier : virtual public Enemy {
	public:
		Olivier();
		Olivier(Olivier const & src);
		Olivier &operator=(Olivier const &rhs);
		virtual ~Olivier();
};

#endif
