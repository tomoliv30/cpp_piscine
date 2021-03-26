/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:19:10 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:50:24 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public virtual AMateria
{
	public:
		Ice();
		Ice(std::string const & name);
		Ice(Ice const & src);
		Ice	&operator=(Ice const & rhs);
		virtual ~Ice();
		std::string const & getType() const; //Returns the materia type
		AMateria *clone() const;
		virtual void use(ICharacter& target);
};

#endif
