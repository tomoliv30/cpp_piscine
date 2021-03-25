/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 13:18:16 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:45:41 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	{
		Fixed a;
		Fixed b(a);
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n\n\t\ttesting setRawBits\n\n";
	{
		Fixed a;
		Fixed b(a);
		Fixed c;
		c = b;

		a.setRawBits(15);
		b.setRawBits(-16);
		c.setRawBits(6);

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	return 0;
}
