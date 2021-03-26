/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Baguette.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:19:59 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 09:53:49 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAGUETTE_HPP
# define BAGUETTE_HPP

# include "AWeapon.hpp"

class Baguette : virtual public AWeapon {
	public:
		Baguette();
		Baguette(AWeapon const & src);
		Baguette &operator=(Baguette const &rhs);
		virtual ~Baguette();
		virtual void	attack() const;
};

#endif
