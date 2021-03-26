/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:58:01 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:15:38 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>

#include "ClapTrap.hpp"
#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"

int	main() {

	srand(time(NULL));

	std::cout << "\t\t --> init ClapTrap ClapTom(\"ClapTom\") <--" << std::endl;
	ClapTrap ClapTom("ClapTom");
	ClapTom.displayStats();

	std::cout << "\t\t --> init FragTrap FragTom(\"FragTom\") <--" << std::endl;
	FragTrap FragTom("FragTom");
	FragTom.displayStats();


	std::cout << "\t\t --> init ScavTrap ScavTom(\"ScavTom\") <--" << std::endl;
	ScavTrap ScavTom("ScavTom");
	ScavTom.displayStats();

	std::cout << "\t\t --> init NinjaTrap NinjaTom(\"NinjaTom\") <--" << std::endl;
	NinjaTrap NinjaTom("NinjaTom");
	NinjaTom.displayStats();

	std::cout << "\t\t --> init SuperTrap SuperTom(\"SuperTom\") <--" << std::endl;
	SuperTrap SuperTom("SuperTom");
	SuperTom.displayStats();


	std::cout << "--> SuperTom has FragTrap rangedAttack..."  << std::endl;
	std::cout << "--> SuperTom.rangedAttack(target 1) ..."  << std::endl;
	SuperTom.rangedAttack("target 1");

	std::cout << "--> SuperTom has NinjaTrap meleeAttack..."  << std::endl;
	std::cout << "--> SuperTom.meleeAttack(target 1) ..."  << std::endl;
	SuperTom.meleeAttack("target 1");

	std::cout << "--> SuperTom has NinjaTrap shoebox functions..."  << std::endl;

	std::cout << "--> SuperTom.ninjaShoebox(ClapTom) ..."  << std::endl;
	SuperTom.ninjaShoebox(ClapTom);
	SuperTom.displayStats();

	std::cout << "--> SuperTom.ninjaShoebox(FragTom) ..."  << std::endl;
	SuperTom.ninjaShoebox(FragTom);
	SuperTom.displayStats();

	std::cout << "--> SuperTom.ninjaShoebox(ScavTom) ..."  << std::endl;
	SuperTom.ninjaShoebox(ScavTom);
	SuperTom.displayStats();

	std::cout << "--> SuperTom.ninjaShoebox(NinjaTom) ..."  << std::endl;
	SuperTom.ninjaShoebox(NinjaTom);
	SuperTom.displayStats();

	std::cout << "--> SuperTom has FragTrap vaulthunter_dot_exe ..."  << std::endl;
	SuperTom.vaulthunter_dot_exe("target 1");
	SuperTom.displayStats();

	std::cout << "exiting main scope" << std::endl;
	return (0);
}


