/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 11:37:59 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/04 10:16:36 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <limits.h>

int		Scalar::convertInt()
{
	if (!validInput() || (_flags >> IS_NAN & 1) 
			|| (_flags >> OVERFLOW  & 1)
			|| this->_raw > INT_MAX 
			|| this->_raw < INT_MIN)
	{
		throw(Scalar::impossibleConversion());
	}
	return (static_cast<int>(this->_raw));
}

void	Scalar::displayInt()
{
	try
	{
		std::cout << "int: " << convertInt() << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}
