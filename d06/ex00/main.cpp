/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 13:37:37 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/03 17:11:49 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <errno.h>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "error: usage: one argument" << std::endl;
		return (1);
	}
	errno = 0;
	Scalar conversion(av[1]);
	conversion.displayChar();
	conversion.displayInt();
	conversion.displayFloat();
	conversion.displayDouble();
	std::cout << std::endl;
	return (0);
}

