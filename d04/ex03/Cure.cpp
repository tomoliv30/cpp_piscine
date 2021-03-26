/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:19:19 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:50:14 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria ("cure")
{
	return;
}

Cure::Cure(std::string const & name) : AMateria ("cure", name)
{
	return;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
}

Cure &Cure::operator=(Cure const & rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure()
{
	return ;
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}
