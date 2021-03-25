/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 13:51:48 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:48:58 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed::Fixed(const float toConvert)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = static_cast<int>(roundf(toConvert * (1 << this->_binaryPoint)));
	if (toConvert < 0) {
		this->_fixedPointValue = std::abs(this->_fixedPointValue);
		this->_fixedPointValue = ~this->_fixedPointValue;
		this->_fixedPointValue++;
	}
}

Fixed::Fixed(const int toConvert)
{
	std::cout << "Int constructor called" << std::endl;
	if (toConvert < 0) {
		this->_fixedPointValue = std::abs(toConvert);
		this->_fixedPointValue = ~this->_fixedPointValue;
		this->_fixedPointValue++;
	}
	this->_fixedPointValue = toConvert << this->_binaryPoint;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const
{
	int	convertedToInt = std::abs(this->_fixedPointValue);
	int	sign = 1;

	if (this->_fixedPointValue < 0) {
		convertedToInt = this->_fixedPointValue - 1;
		convertedToInt = ~convertedToInt;
		sign = -1;
	}
	return ((static_cast<float>(convertedToInt) / (1 << this->_binaryPoint)) * sign);
}

int	Fixed::toInt(void) const
{
	int	convertedToInt = std::abs(this->_fixedPointValue);
	int	sign = 1;

	if (this->_fixedPointValue < 0) {
		convertedToInt = this->_fixedPointValue - 1;
		convertedToInt = ~convertedToInt;
		sign = -1;
	}
	return (static_cast<int>(convertedToInt >> this->_binaryPoint) * sign);
}

int	Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

std::ostream&	operator<<(std::ostream &output, Fixed const &toOutput) {
			output << toOutput.toFloat();
			return (output);
}
