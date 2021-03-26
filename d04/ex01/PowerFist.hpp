/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PowerFist.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:27:31 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 09:53:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include "AWeapon.hpp"

class PowerFist : virtual public AWeapon {
	public:
		PowerFist();
		PowerFist(PowerFist const & src);
		PowerFist &operator=(PowerFist const &rhs);
		virtual ~PowerFist();
		virtual void	attack() const;
};

#endif
