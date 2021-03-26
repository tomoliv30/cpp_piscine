/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tom.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:42:41 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:42:36 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Tom.hpp"

Tom::Tom() : Enemy(80, "Tom") {
	std::cout << "* Tom: ah ah ah*" << std::endl;
	return ;
}

Tom::Tom(Tom const & src) : Enemy(src){
	std::cout << "* Tom: ah ah ah *" << std::endl;
	return ;
}

Tom::~Tom() {
	std::cout << "* Tom dead *"<< std::endl;
	return ;
}

Tom &Tom::operator=(Tom const &rhs)
{
	this->setHP(rhs.getHP());
	return *this;
}

