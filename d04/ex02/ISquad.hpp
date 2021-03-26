/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ISquad.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:26:16 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 13:55:35 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ~ISquad() {};
		virtual int getCount()	 const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;
		virtual int				push(ISpaceMarine*) = 0;
			
};

#endif
