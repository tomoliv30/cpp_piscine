/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 11:36:50 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/04 10:16:05 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <limits.h>

char	Scalar::convertChar()
{
	if (!validInput() || _flags >> IS_NAN & 1
			|| _flags >> OVERFLOW & 1
			|| _raw > SCHAR_MAX 
			|| _raw < SCHAR_MIN)
		throw(Scalar::impossibleConversion());
	else if (!isprint(static_cast<int>(this->_raw)))
		throw(Scalar::nonDisplayable());
	return (static_cast<char>(this->_raw));
}

void	Scalar::displayChar()
{
	try
	{
		std::cout << "char: "; 
		char	c = convertChar();
		std::cout << "'" << c << "'"<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
