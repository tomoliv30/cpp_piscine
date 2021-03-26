/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Knife.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:50:23 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 09:53:48 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIFE_HPP
# define KNIFE_HPP

# include "AWeapon.hpp"

class Knife : virtual public AWeapon {
	public:
		Knife();
		Knife(AWeapon const & src);
		Knife &operator=(Knife const &rhs);
		virtual ~Knife();
		virtual void	attack() const;
};

#endif
