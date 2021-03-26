/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Squad.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:27:04 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:47:01 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class	Squad : virtual public ISquad
{
	private:
		int	_n_unit;
		typedef struct	s_squad
		{
			ISpaceMarine	*unit;
			struct	s_squad *next;
		}				t_squad;
		t_squad			*_squad;
		t_squad			**_currentNode;
	public:
		Squad();
		Squad(Squad const & src);
		virtual ~Squad();
		Squad	&operator=(Squad const & rhs);
		int getCount() const;
		void	clearSquad();
		t_squad *getSquad();
		ISpaceMarine *getUnit(int index) const;
		int	push(ISpaceMarine *interface);
};

#endif
