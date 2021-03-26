/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Carbon.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:18:32 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:48:25 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Carbon.hpp"

Carbon::Carbon() : AMateria("carbon")
{
	return;
}

Carbon::Carbon(std::string const & name) : AMateria("carbon", name)
{
	return;
}

Carbon::Carbon(Carbon const & src) : AMateria(src)
{
}

Carbon &Carbon::operator=(Carbon const & rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

Carbon::~Carbon()
{
	return ;
}

AMateria * Carbon::clone() const
{
	return (new Carbon(*this));
}

void Carbon::use(ICharacter& target)
{
	std::cout << "* throws carbon at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}
