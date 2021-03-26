/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tom.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 15:28:59 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:29:00 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOM_HPP
# define TOM_HPP

# include "Enemy.hpp"

class Tom : virtual public Enemy {
	public:
		Tom();
		Tom(Tom const & src);
		Tom &operator=(Tom const &rhs);
		virtual ~Tom();
};

#endif
