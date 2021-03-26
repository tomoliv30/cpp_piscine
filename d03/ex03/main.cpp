/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:24:12 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:14:23 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <stdlib.h>

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


	std::cout << "--> NinjaTom.ninjaShoebox(FragTom) "<< std::endl;
	NinjaTom.ninjaShoebox(FragTom);
	FragTom.displayStats();
	std::cout << "\t\t\t----"  << std::endl;
	NinjaTom.displayStats();

	std::cout << "--> NinjaTom.ninjaShoebox(ScavTom) "<< std::endl;
	NinjaTom.ninjaShoebox(ScavTom);
	ScavTom.displayStats();
	std::cout << "\t\t\t----"  << std::endl;
	NinjaTom.displayStats();

	std::cout << "--> NinjaTom.ninjaShoebox(NinjaTom) "<< std::endl;
	NinjaTom.ninjaShoebox(NinjaTom);
	NinjaTom.displayStats();

	std::cout << "--> ClapTom.ninjaShoebox(ClapTom) "<< std::endl;
	NinjaTom.ninjaShoebox(ClapTom);
	ClapTom.displayStats();
	std::cout << "\t\t\t----"  << std::endl;
	NinjaTom.displayStats();
	return (0);
}

