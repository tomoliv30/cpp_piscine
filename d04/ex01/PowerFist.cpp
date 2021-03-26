/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PowerFist.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 09:54:53 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:35:06 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {
	return ;
}

PowerFist::PowerFist(PowerFist const & src) :
	AWeapon(src)
{
	return ;
}

PowerFist::~PowerFist() {
	return ;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &PowerFist::operator=(PowerFist const &rhs)
{
	this->setAttributes(rhs.getAttribute(DAMAGE), rhs.getAttribute(AP_COST));
	return *this;
}
