/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 11:42:21 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/04 11:05:28 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <iomanip>
#include <cmath>

double	Scalar::epsilon(double a, double b)
{
	return std::max(std::abs(a), std::abs(b)) * 1e-4;
}

double Scalar::dless(double a, double b)
{
	return a < b + epsilon(a, b);
}

double	Scalar::convertDouble()
{
	if ((_flags >> IS_NAN & 1) || (_flags >> IS_INF & 1))
		return (static_cast<double>(this->_raw));
	if (!validInput() || ((_flags >> OVERFLOW) & 1))
		throw(Scalar::impossibleConversion());
	return (static_cast<double>(this->_raw));
}

void	Scalar::displayDouble()
{
	try
	{
		std::cout << "double: " << std::fixed << std::setprecision(_precision) << convertDouble() << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}
