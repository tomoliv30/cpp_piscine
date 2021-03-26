/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Knife.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 19:20:14 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:34:05 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Knife.hpp"

Knife::Knife() : AWeapon("Knife", 25, 11) {
	return ;
}

Knife::Knife(AWeapon const & src) :
	AWeapon(src)
{
	return ;
}

Knife &Knife::operator=(Knife const &rhs)
{
	this->setAttributes(rhs.getAttribute(DAMAGE), rhs.getAttribute(AP_COST));
	return *this;
}

Knife::~Knife() {
	return ;
}

void Knife::attack() const {
	std::cout << "* ching ching *" << std::endl;
}
