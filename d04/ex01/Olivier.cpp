/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Olivier.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:14:58 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:42:59 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Olivier.hpp"

Olivier::Olivier() : Enemy(70, "Olivier") {
	std::cout << "* Olivier: oi *" << std::endl;
	return ;
}

Olivier::Olivier(Olivier const & src) : Enemy(src)
{
	std::cout << "* Olivier: oi *" << std::endl;
	return ;
}

Olivier::~Olivier() {
	std::cout << "* Olivier dead *"<< std::endl;
	return ;
}

Olivier &Olivier::operator=(Olivier const &rhs)
{
	this->setHP(rhs.getHP());
	return *this;
}
