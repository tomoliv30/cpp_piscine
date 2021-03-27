/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 11:40:53 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/04 11:05:41 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <float.h>
#include <iomanip>
#include <cmath>

float	Scalar::epsilon(float a, float b)
{
	return std::max(std::abs(a), std::abs(b)) * 1e-4;
}

float	Scalar::fless(float a, float b)
{
	return a < b + epsilon(a, b);
}

float	Scalar::convertFloat()
{
	if ((_flags >> IS_NAN & 1) || (_flags >> IS_INF & 1))
		return (static_cast<float>(this->_raw));
	if (!validInput()|| !dless(std::abs(_raw), FLT_MAX)
			|| (_flags >> OVERFLOW & 1))
		throw(Scalar::impossibleConversion());
	return (static_cast<float>(this->_raw));
}

void	Scalar::displayFloat()
{
	try
	{
		std::cout << "float : " << std::fixed << std::setprecision(_precision) << convertFloat() << "f" << std::endl;
		
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}
