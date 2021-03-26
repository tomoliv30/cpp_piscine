/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ISpaceMarine.hpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:49:18 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 14:03:27 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACE_MARINE_HPP
# define ISPACE_MARINE_HPP


class ISpaceMarine
{
	public:
		virtual ~ISpaceMarine() {}
		virtual ISpaceMarine* clone() const = 0;
		virtual void battleCry() const = 0;
		virtual void rangedAttack() const = 0;
		virtual void meleeAttack() const = 0;
};

#endif
