/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:18:32 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:50:37 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return;
}

Ice::Ice(std::string const & name) : AMateria("ice", name)
{
	return;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
}

Ice &Ice::operator=(Ice const & rhs)
{
	AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice()
{
	return ;
}

AMateria * Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}
