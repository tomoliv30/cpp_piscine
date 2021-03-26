/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Nuke.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 15:59:40 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/29 09:51:11 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Nuke.hpp"
#include <limits.h>

Nuke::Nuke() : AWeapon("Nuke", 40, INT_MAX) {
	return ;
}

Nuke::Nuke(AWeapon const & src) :
	AWeapon(src)
{
	return ;
}

Nuke::~Nuke() {
	return ;
}

void Nuke::attack() const {
	std::cout << "* (_(_(_(_****_)_)_)_) *" << std::endl;
}

Nuke &Nuke::operator=(Nuke const &rhs)
{
	this->setAttributes(rhs.getAttribute(DAMAGE), rhs.getAttribute(AP_COST));
	return *this;
}
