/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 13:55:40 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 10:46:57 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <stdlib.h>

int	main() {
	srand(time(NULL));

	std::cout << "\t\t --> init FragTrap FragTom(\"FragTom\") <--" << std::endl;
	FragTrap FragTom("FragTom");
	FragTom.displayStats();

	std::cout << "--> FragTom.meleeAttack(\"target 1\") "<< std::endl;
	FragTom.meleeAttack("target 1");
	std::cout << "--> FragTom.rangedAttack(\"target 1\") "<< std::endl;
	FragTom.rangedAttack("target 1");

	std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 1\") "<< std::endl;
	FragTom.vaulthunter_dot_exe("target 1");
	FragTom.displayStats();
	std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 2\") "<< std::endl;
	FragTom.vaulthunter_dot_exe("target 2");
	FragTom.displayStats();
	std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 3\") "<< std::endl;
	FragTom.vaulthunter_dot_exe("target 3");
	FragTom.displayStats();
	std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 4\") "<< std::endl;
	FragTom.vaulthunter_dot_exe("target 4");
	FragTom.displayStats();
	std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 5\") "<< std::endl;
	FragTom.vaulthunter_dot_exe("target 5");

	std::cout << "take damage handles armor damage reduction and hit points can't fall below 0" << std::endl;
	std::cout << "takeDamage(17)" << std::endl;
	FragTom.takeDamage(17);
	FragTom.displayStats();
	std::cout << "takeDamage(27)" << std::endl;
	FragTom.takeDamage(27);
	FragTom.displayStats();
	std::cout << "takeDamage(0)" << std::endl;
	FragTom.takeDamage(0);
	FragTom.displayStats();
	std::cout << "takeDamage(5)" << std::endl;
	FragTom.takeDamage(5);
	FragTom.displayStats();
	std::cout << "takeDamage(24)" << std::endl;
	FragTom.takeDamage(24);
	FragTom.displayStats();
	std::cout << "takeDamage(24)" << std::endl;
	FragTom.takeDamage(24);
	FragTom.displayStats();
	std::cout << "takeDamage(4)" << std::endl;
	FragTom.takeDamage(4);
	FragTom.displayStats();
	std::cout << "takeDamage(40)" << std::endl;
	FragTom.takeDamage(40);
	FragTom.displayStats();
	std::cout << "takeDamage(1)" << std::endl;
	FragTom.takeDamage(1);
	FragTom.displayStats();


	std::cout << "hp can't exceed max hp" << std::endl;

	std::cout << "beRepaired(100)" << std::endl;
	FragTom.beRepaired(100);
	FragTom.displayStats();

	std::cout << "beRepaired(1)" << std::endl;
	FragTom.beRepaired(100);
	FragTom.displayStats();

	std::cout << "exiting main scope..." << std::endl;
	return (0);
}
