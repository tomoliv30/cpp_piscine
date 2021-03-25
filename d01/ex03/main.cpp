/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 23:18:17 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:08:03 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <stdlib.h>

int	main()
{
	srand(time(NULL));
	std::cout << "\t\tCreating zombie horde...\n" << std::endl;
	try
	{
		ZombieHorde *horde = new ZombieHorde(6);
		std::cout << "\n\n\t\tCalling horde.announce()...\n" << std::endl;
		horde->announce();
		std::cout << "\n\n\t\tDeleting horde.....\n" << std::endl;
		delete horde;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
