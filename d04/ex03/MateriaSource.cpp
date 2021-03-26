/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:18:36 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:52:49 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _name("default"), _n_materia(0)
{
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
	}
    return ;
}

MateriaSource::MateriaSource(MateriaSource const & src) : _n_materia(0)
{
	*this = src;
	return ;
}

MateriaSource::MateriaSource(std::string const & name) : _name(name), _n_materia(0)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

MateriaSource       &MateriaSource::operator=(MateriaSource const & rhs)
{
    for (unsigned int i = 0; i < _n_materia; i++)
    {
        delete this->_inventory[i];
	    if (i < rhs._n_materia)
        	this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
    }
    this->_n_materia = rhs._n_materia;
	return *this;
}

MateriaSource::~MateriaSource()
{
    for (unsigned int i = 0; i < _n_materia; i++)
    {
        delete this->_inventory[i];
	   	this->_inventory[i] = NULL;
    }
	return ;
}

AMateria    *MateriaSource::createMateria(std::string const & type)
{
	for  (unsigned int i = 0; i < _n_materia; i++) {
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}

void        MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	if (this->_n_materia < 4)
	{
		this->_inventory[this->_n_materia] = m;
		this->_n_materia++;
	}
}

void				MateriaSource::displayInventory()
{
	std::cout << "--> name: " << _name << " n_materia: " << _n_materia << std::endl;
	std::cout << "\t\tinventory" << std::endl;
	for (unsigned int i = 0; i < _n_materia; i++) {
		std::cout << "\t\t\t(" << i << ")---";
		_inventory[i]->displayStats();
	}
}
