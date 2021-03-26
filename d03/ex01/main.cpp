/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 18:54:41 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 10:49:55 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <math.h>
#include <stdlib.h>

int	main() {
	srand(time(NULL));

		std::cout << "\t\tcomparing both classes\n\n";
	{
		std::cout << "\t\t --> init FragTrap FragTom(\"FragTom\") <--" << std::endl;
		FragTrap FragTom("FragTom");
		FragTom.displayStats();
		std::cout << "\t\t --> init NinjaTrap NinjaTom(\"NinjaTom\") <--" << std::endl;
		ScavTrap ScavTom("ScavTom");
		ScavTom.displayStats();


		std::cout << "--> ScavTom.meleeAttack(\"target 1\") "<< std::endl;
		ScavTom.meleeAttack("target 1");
		std::cout << "--> FragTom.meleeAttack(\"target 1\") "<< std::endl;
		FragTom.meleeAttack("target 1");
		std::cout << "--> ScavTom.rangedAttack(\"target 2\") "<< std::endl;
		ScavTom.rangedAttack("target 1");
		std::cout << "--> FragTom.rangedAttack(\"target 2\") "<< std::endl;
		FragTom.rangedAttack("target 1");

		std::cout << "--> ScavTom.challengeNewcomer(\"target 1\") "<< std::endl;
		ScavTom.challengeNewcomer("target 1");
		ScavTom.displayStats();
		std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 1\") "<< std::endl;
		FragTom.vaulthunter_dot_exe("target 1");
		FragTom.displayStats();
	}
	std::cout << "\n\n\t\t same tests as ex00 with ScavTrap\n\n";
	{
		std::cout << "\t\t --> init ScavTrap ScavTom(\"ScavTom\") <--" << std::endl;
		ScavTrap ScavTom("ScavTom");
		ScavTom.displayStats();

		std::cout << "--> ScavTom.meleeAttack(\"target 1\") "<< std::endl;
		ScavTom.meleeAttack("target 1");
		std::cout << "--> ScavTom.rangedAttack(\"target 1\") "<< std::endl;
		ScavTom.rangedAttack("target 1");

		std::cout << "--> ScavTom.challengeNewcomer(\"target 1\") "<< std::endl;
		ScavTom.challengeNewcomer("target 1");
		ScavTom.displayStats();
		std::cout << "--> ScavTom.challengeNewcomer(\"target 2\") "<< std::endl;
		ScavTom.challengeNewcomer("target 2");
		ScavTom.displayStats();
		std::cout << "--> ScavTom.challengeNewcomer(\"target 3\") "<< std::endl;
		ScavTom.challengeNewcomer("target 3");
		ScavTom.displayStats();

		std::cout << "take damage handles armor damage reduction and hit points can't fall below 0" << std::endl;
		std::cout << "takeDamage(17)" << std::endl;
		ScavTom.takeDamage(17);
		ScavTom.displayStats();
		std::cout << "takeDamage(27)" << std::endl;
		ScavTom.takeDamage(27);
		ScavTom.displayStats();
		std::cout << "takeDamage(0)" << std::endl;
		ScavTom.takeDamage(0);
		ScavTom.displayStats();
		std::cout << "takeDamage(3)" << std::endl;
		ScavTom.takeDamage(3);
		ScavTom.displayStats();
		std::cout << "takeDamage(24)" << std::endl;
		ScavTom.takeDamage(24);
		ScavTom.displayStats();
		std::cout << "takeDamage(24)" << std::endl;
		ScavTom.takeDamage(24);
		ScavTom.displayStats();
		std::cout << "takeDamage(4)" << std::endl;
		ScavTom.takeDamage(4);
		ScavTom.displayStats();
		std::cout << "takeDamage(40)" << std::endl;
		ScavTom.takeDamage(40);
		ScavTom.displayStats();
		std::cout << "takeDamage(1)" << std::endl;
		ScavTom.takeDamage(1);
		ScavTom.displayStats();


		std::cout << "hp can't exceed max hp" << std::endl;

		std::cout << "beRepaired(100)" << std::endl;
		ScavTom.beRepaired(100);
		ScavTom.displayStats();

		std::cout << "beRepaired(1)" << std::endl;
		ScavTom.beRepaired(100);
		ScavTom.displayStats();

		std::cout << "exiting main scope..." << std::endl;
	}
	return (0);
}
