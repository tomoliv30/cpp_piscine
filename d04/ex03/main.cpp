/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:19:05 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/29 10:33:09 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Carbon.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{

	{
		std::cout << "exercise's main\n\n";

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << "tmp = src->createMateria(\"noexist\")" << std::endl;
		tmp = src->createMateria("noexist");
		if (!tmp)
			std::cout << "tmp == NULL" << std::endl;
		else
			std::cout << "createMateria didn't return NULL" << std::endl;
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n\n";

	std::cout << "new materiasource through IMateriaSource*" << std::endl;
	IMateriaSource* InterfaceMateriaSource = new MateriaSource("IMateriaSource");
	//cannot display stats because displayStats function not in Interface
	std::cout << "new materiasource through MateriaSource*" << std::endl;
	MateriaSource* ConcretMateriaSource = new MateriaSource("MateriaSource");
	ConcretMateriaSource->displayInventory();

	std::cout << "new Character through ICharacter*" << std::endl;
	ICharacter* InterfaceCharacter = new Character("InterfaceCharacter");
	//cannot display stats because displayStats function not in Interface
	std::cout << "new Character through Character*" << std::endl;
	Character * ConcreteCharacter= new Character("ConcreteCharacter");
	ConcreteCharacter->displayInventory();

	std::cout << "new Ice through AMateria *" << std::endl;
	AMateria *AbstractIce = new Ice("AbstractIce");
	AbstractIce->displayStats();
	std::cout << "new Ice through Ice *" << std::endl;
	Ice		*ConcreteIce = new Ice("ConcreteIce");
	ConcreteIce->displayStats();
	std::cout << "new Cure through AMateria *" << std::endl;
	AMateria *AbstractCure = new Cure("AbstractCure");
	AbstractCure->displayStats();
	std::cout << "new Cure through Cure *" << std::endl;
	Cure	*ConcreteCure = new Cure("ConcreteCure");
	ConcreteCure->displayStats();
	std::cout << "new Carbon through AMateria *" << std::endl;
	AMateria *AbstractCarbon = new Carbon("AbstractCarbon");
	AbstractCarbon->displayStats();
	std::cout << "new Carbon through Carbon *" << std::endl;
	Carbon	*ConcreteCarbon = new Carbon("ConcreteCarbon");
	ConcreteCarbon->displayStats();

	std::cout << "\n\n";

	std::cout << "testing clone and use" << std::endl;

	std::cout << "ConcreteIce->use(ConcreteCharacter)" << std::endl;
	ConcreteIce->use(*ConcreteCharacter);
	std::cout << "AbstractCure->use(ConcreteCharacter)" << std::endl;
	AbstractCure->use(*ConcreteCharacter);
	AMateria *tmp = ConcreteIce->clone();
	std::cout << "tmp = ConcreteIce->clone()" << std::endl;
	tmp->displayStats();
	std::cout << "ConcreteIce->use(ConcreteCharacter)" << std::endl;
	ConcreteIce->use(*ConcreteCharacter);
	std::cout << "ConcreteIce->use(InterfaceCharacter)" << std::endl;
	ConcreteIce->use(*InterfaceCharacter);
	ConcreteIce->displayStats();
	tmp->displayStats();

	std::cout << "cloning Cure into tmp" << std::endl;
	delete tmp;
	tmp = AbstractCure->clone();
	tmp->displayStats();

	std::cout << "\n\n";

	std::cout << "testing character inventory" << std::endl;

	ConcreteCharacter->displayInventory();


	std::cout << "ConcreteCharacter->unequip(0) (empty inventory)" << std::endl;
	ConcreteCharacter->unequip(0);
	std::cout << "ConcreteCharacter->equip(AbstractIce)" << std::endl;
	ConcreteCharacter->equip(AbstractIce);
	ConcreteCharacter->displayInventory();
	std::cout << "ConcreteCharacter->equip(ConcreteCure)" << std::endl;
	ConcreteCharacter->equip(ConcreteCure);
	ConcreteCharacter->displayInventory();
	std::cout << "ConcreteCharacter->equip(AbstractCure) nothe" << std::endl;
	ConcreteCharacter->equip(AbstractCure);
	ConcreteCharacter->displayInventory();
	std::cout << "ConcreteCharacter->equip(ConcreteCarbon)" << std::endl;
	ConcreteCharacter->equip(ConcreteCarbon);
	ConcreteCharacter->displayInventory();

	std::cout << "One more item?" << std::endl;
	std::cout << "ConcreteCharacter->equip(AbstractCarbon)" << std::endl;

	ConcreteCharacter->equip(AbstractCarbon);
	ConcreteCharacter->displayInventory();
//
	std::cout << "Testing unequip .." << std::endl;
	std::cout << "ConcreteCharacter->unequip(1) (ConcreteCure)" << std::endl;
	ConcreteCharacter->unequip(1);
	ConcreteCharacter->displayInventory();

	std::cout << "ConcreteCharacter->unequip(0) (ConcreteCure)" << std::endl;
	ConcreteCharacter->unequip(0);
	ConcreteCharacter->displayInventory();
//
	std::cout << "testing use in character" << std::endl;
	std::cout << "ConcreteCharacter->use(0, *InterfaceCharacter)" << std::endl;
	ConcreteCharacter->use(0, *InterfaceCharacter);
	std::cout << "ConcreteCharacter->use(2, *InterfaceCharacter) doesnt exist" << std::endl;
	ConcreteCharacter->use(2, *InterfaceCharacter);
	std::cout << "ConcreteCharacter->use(1, *InterfaceCharacter)" << std::endl;
	ConcreteCharacter->use(1, *InterfaceCharacter);
	std::cout << "ConcreteCharacter->use(3, *InterfaceCharacter)" << std::endl;
	ConcreteCharacter->use(3, *InterfaceCharacter);

	std::cout << "ConcreteCharacter->use(-1, *InterfaceCharacter)" << std::endl;
	ConcreteCharacter->use(-1, *InterfaceCharacter);
	std::cout << "ConcreteCharacter->use(40, *InterfaceCharacter)" << std::endl;
	ConcreteCharacter->use(40, *InterfaceCharacter);
	std::cout << "limits of use" << std::endl;
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCharacter->use(1, *InterfaceCharacter);
	ConcreteCarbon->displayStats();

//
	std::cout << "Copy of Character must be deep.." << std::endl;
	std::cout << "*Copy Character = new ConcreteCharacter" << std::endl;
	Character *CopyCharacter = new Character(*ConcreteCharacter);
	std::cout << "Assign Character(ConcreteCharacter)" << std::endl;
	Character AssignCharacter(*ConcreteCharacter);
	std::cout << "ConcreteCharacter->unequip(0)" << std::endl;
	ConcreteCharacter->unequip(0);
	ConcreteCharacter->displayInventory();
	std::cout << "AssignCharacter = *ConcreteCharacter (old materia will be deleted)" << std::endl;
	AssignCharacter =  *ConcreteCharacter;
	AssignCharacter.displayInventory();
	std::cout << "deleting CopyCharacter (deleting its materia).." << std::endl;
	delete CopyCharacter;
	std::cout << "unchanged in ConcreteCharacter.." << std::endl;
	ConcreteCharacter->displayInventory();
	std::cout << "unchanged in assign character.." << std::endl;
	AssignCharacter.displayInventory();
//
	std::cout << "deleting Characters/MateriaSource will delete their materia (no leaks)" << std::endl;
	std::cout << "deleting InterfaceCharacter and ConcreteCharacter" << std::endl;

	delete InterfaceCharacter;
	delete ConcreteCharacter;


	std::cout << "ConcreteCharacter = new Character(\"ConcreteCharacter\")" << std::endl;
	std::cout << "Character *LastCharacter = ConcreteCharacter" << std::endl;
	ConcreteCharacter = new Character("ConcreteCharacter");
	Character *LastCharacter = new Character("LastCharacter");

	std::cout << "storing 4 materia into ConcretMateriaSource..." << std::endl;

	ConcretMateriaSource->learnMateria(AbstractIce);
	ConcretMateriaSource->learnMateria(ConcreteIce);
	ConcretMateriaSource->learnMateria(AbstractCure);
	ConcretMateriaSource->learnMateria(ConcreteCure);

	ConcretMateriaSource->displayInventory();

	std::cout << "equiping ConcreteCharacter with remaing materia ..." << std::endl;

	ConcreteCharacter->equip(AbstractCarbon);
	ConcreteCharacter->displayInventory();

	std::cout << "ConcreteCharacter = LastCharacter (copy will be deep, thus abstract carbon will be deleted)" << std::endl;
	*ConcreteCharacter = *LastCharacter;
	ConcreteCharacter->displayInventory();
	std::cout << "equiping ConcreteCharacter with clones of materias" << std::endl;
	std::cout << "equip(ConcretMateriaSource->createMateria(\"ice\")" << std::endl;
	ConcreteCharacter->equip(ConcretMateriaSource->createMateria("ice"));
	std::cout << "equip(ConcretMateriaSource->createMateria(\"cure\")" << std::endl;
	ConcreteCharacter->equip(ConcretMateriaSource->createMateria("cure"));
	std::cout << "equip(ConcretMateriaSource->createMateria(\"noexist\")" << std::endl;
	ConcreteCharacter->equip(ConcretMateriaSource->createMateria("noexist"));
	ConcreteCharacter->displayInventory();


	std::cout << "delete everything" << std::endl;


	delete InterfaceMateriaSource; 
	delete ConcretMateriaSource;
	delete ConcreteCharacter;
	delete LastCharacter;
	delete tmp;
	//system("leaks ex03");
	return 0;
}
