/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:19:14 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:50:06 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const & name);
		Cure(Cure const & src);
		Cure	&operator=(Cure const & rhs);
		virtual ~Cure();
		std::string const & getType() const; //Returns the materia type
		Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif
