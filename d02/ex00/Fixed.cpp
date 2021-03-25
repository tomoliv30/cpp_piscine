/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 13:14:08 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:44:22 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
