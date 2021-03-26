/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 15:07:17 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/29 10:35:00 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Baguette.hpp"
#include "Nuke.hpp"
#include "Knife.hpp"
#include "Tom.hpp"
#include "Olivier.hpp"

int main()
{
	std::cout << "subject's main" << std::endl;
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;


	std::cout << "\n\n" << std::endl;

	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	std::cout << "creating baguette knife (weapons), tom olivier (enemies) and me2 (character)" << std::endl;
	Character me2("me2");
	AWeapon * baguette = new Baguette();
	AWeapon * knife = new Knife();
	Enemy *tom = new Tom();
	Enemy *olivier = new Olivier();

	std::cout << "me2.attack(tom)" << std::endl;
	me2.attack(tom);
	std::cout << me2;
	std::cout << "me2.equip(baguette)" << std::endl;
	me2.equip(baguette);
	std::cout << me2;
	std::cout << "me2.equip(knife)" << std::endl;
	me2.equip(knife);
	std::cout << me2;


	me2.attack(tom);
	me2.attack(tom);

	std::cout << "me2.equip(baguette)" << std::endl;
	me2.equip(baguette);
	std::cout << me2;

	me2.attack(olivier);
	me2.attack(olivier);
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	std::cout << me2;
	me2.recoverAP();

	std::cout << "creating super mutant (enemy) and nuke (weapon)" << std::endl;
	Enemy *mutant = new SuperMutant();
	Nuke *nuke = new Nuke();

	me2.attack(mutant);
	me2.attack(mutant);
	std::cout << me2;
	me2.recoverAP();
	me2.recoverAP();

	std::cout << "me2.equip(knife)" << std::endl;
	me2.equip(knife);
	std::cout << me2;
	me2.attack(mutant);
	std::cout << me2;
	me2.attack(mutant);

	std::cout << "me2.equip(nuke)" << std::endl;
	me2.equip(nuke);
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	std::cout << me2;
	me2.attack(mutant);
	std::cout << me2;
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.attack(tom);
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.recoverAP();
	me2.attack(olivier);

	std::cout << "deleting weapons" << std::endl;
	delete knife;
	delete baguette;
	delete pr;
	delete pf;
	delete nuke;
	delete me;
	//system("leaks ex01");
	return (0);
}
