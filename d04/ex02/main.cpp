/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 16:51:41 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/29 10:35:44 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include <iostream>

int	main()
{
	std::cout << "\t\texercise's main" << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		delete vlc;
	}
	std::cout << "\n\n";
	{
		std::cout << "bob = new TacticalMarine" << std::endl;
		ISpaceMarine* bob = new TacticalMarine;
		std::cout << "jim = new AssaultTerminator" << std::endl;
		ISpaceMarine* jim = new AssaultTerminator;
		std::cout << "vlc = new Squad" << std::endl;
		Squad* vlc = new Squad;
		std::cout << "vlc->push(NULL) returns " << vlc->push(NULL) << std::endl;
		std::cout << "vlc->push(bob) returns " << vlc->push(bob) << std::endl;
		std::cout << "vlc >push(jim) returns " << vlc->push(jim) << std::endl;
		std::cout << "vlc->push(NULL) returns " << vlc->push(NULL) << std::endl;
		std::cout << "\nassignation must be deep" << std::endl;
		std::cout << "Squad vlc2(*vlc) will call constructor logs of vlc units" << std::endl;
		Squad vlc2(*vlc);
		std::cout << "calling all attacks of every unit" << std::endl;
		for (int i = 0; i < vlc2.getCount(); ++i)
		{
			std::cout << "unit " << i << std::endl;
			ISpaceMarine* cur = vlc2.getUnit(i);
			std::cout << "..battleCry" << std::endl;
			cur->battleCry();
			std::cout << "..rangedAttack " << std::endl;
			cur->rangedAttack();
			std::cout << "..meleeAttack" << std::endl;
			cur->meleeAttack();
		}
		std::cout << "\ndeleting vlc doesnt delete units in vlc2.." << std::endl;
		std::cout << "delete vlc" << std::endl;
		delete vlc;
		std::cout << "calling all units on vlc2" << std::endl;
		for (int i = 0; i < vlc2.getCount(); ++i)
		{
			std::cout << "unit " << i << std::endl;
			ISpaceMarine* cur = vlc2.getUnit(i);
			std::cout << "..battleCry" << std::endl;
			cur->battleCry();
			std::cout << "..rangedAttack " << std::endl;
			cur->rangedAttack();
			std::cout << "..meleeAttack" << std::endl;
			cur->meleeAttack();
		}
		std::cout << "\nSquad vlc3" << std::endl;
		Squad vlc3;

		std::cout << "unit = new TacticalMarine" << std::endl;
		TacticalMarine	*unit = new TacticalMarine;


		std::cout << "vlc3.push(new TacticalMarine) returns " <<  vlc3.push(new TacticalMarine) << std::endl;
		std::cout << "vlc3.push(unit) returns " << vlc3.push(unit) << std::endl;
		std::cout << "vlc3.push(new AssaultTerminator) returns " << vlc3.push(new AssaultTerminator) << std::endl;
		std::cout << "vlc3.push(unit) returns " << vlc3.push(unit) <<std::endl;
		std::cout << "vlc3.push(NULL) returns " << vlc3.push(NULL) <<std::endl;

		std::cout << "\ncopy must be deep..." << std::endl;
		std::cout << "vlc3 = vlc2 (will call destructors of all units in vlc3 and constructors of all units in vlc2)" << std::endl;
		vlc3 = vlc2;
		std::cout  << "exiting scope" << std::endl;
	}
	//system("leaks ex02");
	return (0);
}
