/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Carbon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:53:37 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:48:18 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARBON_HPP
# define CARBON_HPP

# include "AMateria.hpp"

class Carbon : public virtual AMateria
{
	public:
		Carbon();
		Carbon(std::string const & name);
		Carbon(Carbon const & src);
		Carbon	&operator=(Carbon const & rhs);
		virtual ~Carbon();
		std::string const & getType() const; //Returns the materia type
		AMateria *clone() const;
		virtual void use(ICharacter& target);
};

#endif
