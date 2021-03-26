/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   TacticalMarine.hpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:07:48 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 14:05:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : virtual public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const & src);
		virtual ~TacticalMarine();
		TacticalMarine &operator=(TacticalMarine const &);
		TacticalMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif
