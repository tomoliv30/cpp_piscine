/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Nuke.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 16:02:45 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 16:03:16 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUKE_HPP
# define NUKE_HPP

# include "AWeapon.hpp"

class Nuke : virtual public AWeapon {
	public:
		Nuke();
		Nuke(AWeapon const & src);
		Nuke &operator=(Nuke const &rhs);
		virtual ~Nuke();
		virtual void	attack() const;
};

#endif
