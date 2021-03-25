/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:00:29 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/17 17:05:55 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::~Brain() 
{
	std::cout << "Brain died" << std::endl;
	return ;
}

Brain::Brain()
{
	std::stringstream stream;
	stream << this;
	_address = stream.str();
	std::cout << "Brain created" << std::endl;
}

std::string	Brain::identify()  const
{
	return this->_address;
}

Brain::Brain(Brain const &src)
{
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}
