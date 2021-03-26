/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RadScorpion.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:42:41 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 11:29:38 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const & src)  : Enemy(src)
{
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *"<< std::endl;
	return ;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &rhs)
{
	this->setHP(rhs.getHP());
	return *this;
}
