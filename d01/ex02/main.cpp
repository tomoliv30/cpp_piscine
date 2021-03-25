/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 18:01:19 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:06:33 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <stdlib.h>

int	main()
{
	srand(time(NULL));
	ZombieEvent newEvent;
	std::cout << "\t\tCreating default zombie on the stack...\n" << std::endl;
	Zombie def;
	def.announce();
	std::cout << "\n\n\t\tSetting type for default zombie...\n" << std::endl;
	newEvent.setZombieType(&def);
	def.announce();
	std::cout << "\n\n\t\tCreating a bunch of random zombies...\n" << std::endl;
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	newEvent.randomChump();
	std::cout << "\n\n\t\tUsing newZombie to create a zombie...\n" << std::endl;
	Zombie*	olivier = newEvent.newZombie("olivier");
	olivier->announce();
	std::cout << "\n\n\t\tdeleting manually created new zombie...\n" << std::endl;
	delete olivier;
	std::cout << "\n\n\t\texiting main scope...\n" << std::endl;
	return 0;
}
