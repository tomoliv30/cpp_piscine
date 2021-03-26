/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AssaultTerminator.hpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:12:07 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:45:43 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULT_TERMINATOR_HPP
# define ASSAULT_TERMINATOR_HPP

#include "ISpaceMarine.hpp"

class	AssaultTerminator : virtual public ISpaceMarine
{
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const & src);
		virtual ~AssaultTerminator(void);
		AssaultTerminator &operator=(AssaultTerminator const &);
		AssaultTerminator* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};


#endif
