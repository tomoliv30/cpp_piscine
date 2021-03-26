/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:18:48 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:49:42 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : 
	_name("default"),
	_n_materia(0)
{
	for (int i = 0; i < 4; i++) 
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src) : 
	_name("default"), 
	_n_materia(0)
{
	*this = src;
}

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_n_materia = 0;
	for (int i = 0; i < 4; i++) 
		this->_inventory[i] = NULL;
}

void				Character::cloneInventory(Character const & rhs)
{
	for (unsigned int i = 0; i < _n_materia; i++)
		this->_inventory[i] = rhs._inventory[i]->clone();
}

Character                   &Character::operator=(Character const & rhs)
{
	for (unsigned int i = 0; i < _n_materia; i++)
			delete this->_inventory[i];
	this->_name = rhs._name;
	this->_n_materia = rhs._n_materia;
	cloneInventory(rhs);
	return (*this);
}

const std::string	&Character::getName() const
{
	return this->_name;
}

unsigned int Character::getNMateria() const
{
	return this->_n_materia;
}

void	Character::equip(AMateria* m)
{
	if (!m || _n_materia == 4)
		return ;
	this->_inventory[_n_materia] = m;
	_n_materia++;
}

void 	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4) {
		std::cerr << "index out of bound" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
		return ;
	this->_inventory[idx] = NULL;
	_n_materia--;
	while (idx < 3) {
		this->_inventory[idx] = this->_inventory[idx + 1];
		this->_inventory[idx + 1] = NULL;
		idx++;
	}
}

Character::~Character()
{ 
	std::cout << "Character destructor called for " << _name << std::endl;
	for (unsigned int i = 0; i < _n_materia; i++)
			delete (this->_inventory[i]);
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4) {
		std::cout << "index out of bound" << std::endl;
		return ;
	}
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
	}
}

void	Character::displayInventory()
{
	std::cout << "--> name: " << _name << " n_materia: " << _n_materia << std::endl;
	std::cout << "\t\tinventory" << std::endl;
	for (unsigned int i = 0; i < _n_materia; i++) {
		std::cout << "\t\t\t(" << i << ")---";
		_inventory[i]->displayStats();
	}
}
