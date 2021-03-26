/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PlasmaRifle.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:21:54 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:35:15 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) :
	AWeapon(src)
{
	return ;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	this->setAttributes(rhs.getAttribute(DAMAGE), rhs.getAttribute(AP_COST));
	return *this;
}

PlasmaRifle::~PlasmaRifle() {
	return ;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
