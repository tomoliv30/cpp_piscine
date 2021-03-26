/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:18:06 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:13:12 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <stdlib.h>

int	main() 
{
	srand(time(NULL));
	std::cout << "\t\t --> init ClapTrap ClapTom(\"ClapTom\") <--" << std::endl;
	ClapTrap ClapTom("ClapTom");
	ClapTom.displayStats();
	std::cout << "\t\t --> init FragTrap FragTom(\"FragTom\") <--" << std::endl;
	FragTrap FragTom("FragTom");
	FragTom.displayStats();
	std::cout << "\t\t --> init ScavTrap ScavTom(\"NinjaTom\") <--" << std::endl;
	ScavTrap ScavTom("ScavTom");
	ScavTom.displayStats();

	std::cout << "--> FragTom.meleeAttack(\"target 1\") "<< std::endl;
	FragTom.meleeAttack("target 1");
	std::cout << "--> ScavTom.meleeAttack(\"target 1\") "<< std::endl;
	ScavTom.meleeAttack("target 1");
	std::cout << "--> FragTom.rangedAttack(\"target 1\") "<< std::endl;
	FragTom.rangedAttack("target 1");
	std::cout << "--> ScavTom.rangedAttack(\"target 1\") "<< std::endl;
	ScavTom.rangedAttack("target 1");


	std::cout << "--> ScavTom.challengeNewcomer(\"target 1\") "<< std::endl;
	ScavTom.challengeNewcomer("target 1");
	ScavTom.displayStats();
	std::cout << "--> FragTom.vaulthunter_dot_exe(\"target 1\") "<< std::endl;
	FragTom.vaulthunter_dot_exe("target 1");
	FragTom.displayStats();

	std::cout << "exiting main scope..." << std::endl;
	return (0);
}
