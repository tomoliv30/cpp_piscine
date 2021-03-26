/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PlasmaRifle.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:19:29 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 14:34:45 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : virtual public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const & src);
		PlasmaRifle &operator=(PlasmaRifle const &rhs);
		virtual ~PlasmaRifle();
		virtual void	attack() const;
};

#endif
