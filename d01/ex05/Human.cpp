/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Human.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:13:00 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/19 10:35:23 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()  : _name("John"), _age(25)
{
	std::cout << "Human " << _name << " aged " << _age << " created." << std::endl;
	return ;
}

Human::~Human() 
{
	std::cout << "Human " << _name << " aged " << _age << " is about to die." << std::endl;
	return ;
}

std::string	Human::identify()
{
	return this->getBrain().identify();
}

Human::Human(Human const &src)
{
	*this = src;
}

Human &Human::operator=(Human const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

const Brain	&Human::getBrain() const
{
	return this->_brain;
}
