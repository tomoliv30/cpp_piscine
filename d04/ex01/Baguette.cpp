/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Baguette.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:20:14 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:59:47 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Baguette.hpp"

Baguette::Baguette() : AWeapon("Baguette", 15, 31) {
	return ;
}

Baguette::Baguette(AWeapon const & src) :
	AWeapon(src)
{
	return ;
}

Baguette::~Baguette() {
	return ;
}

void Baguette::attack() const {
	std::cout << "* bread noise *" << std::endl;
}

Baguette &Baguette::operator=(Baguette const &rhs)
{
	this->setAttributes(rhs.getAttribute(DAMAGE), rhs.getAttribute(AP_COST));
	return *this;
}
