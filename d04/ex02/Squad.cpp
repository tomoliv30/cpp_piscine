/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Squad.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:42:45 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:46:55 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>


Squad::Squad() :
	_n_unit(0),
	_squad(NULL),
	_currentNode(&_squad)
{
	return ;
}

Squad::Squad(Squad const & src) : _n_unit(0), _squad(NULL), _currentNode(&_squad)
{
	*this = src;
	return ;
}

Squad::~Squad()
{
	clearSquad();
	return ;
}

Squad &Squad::operator=(Squad const & rhs)
{
	int	current_unit = 0;
	int	n_unit = rhs.getCount();

	clearSquad();
	while (current_unit < n_unit) {
		push((rhs.getUnit(current_unit))->clone());
		current_unit++;
	}
	return *this;
}


int	Squad::getCount() const
{
	return this->_n_unit;
}

ISpaceMarine *Squad::getUnit(int index) const
{
	t_squad *tmpSquad;

	if (index >= getCount() || index < 0 || !_squad)
		return (NULL);
	tmpSquad = _squad;
	while (index)
	{
		tmpSquad = tmpSquad->next;
		index--;
	}
	return (tmpSquad->unit);
}

void	Squad::clearSquad()
{
	unsigned int	n_unit = this->_n_unit;
	t_squad	*next;
	t_squad	*current = this->_squad;

	while (n_unit)
	{
		next = current->next;
		if (current->unit)
			delete current->unit;
		delete current;
		current = next;
		n_unit--;
	}
	this->_squad = NULL;
	this->_currentNode = &(this->_squad);
	this->_n_unit = 0;
}

int	Squad::push(ISpaceMarine *interface)
{
	t_squad	*tmpSquad = _squad;
	int current_unit = 0;

	try
	{
		if (!interface)
			return this->_n_unit;
		if (!this->_n_unit)
		{
			(*_currentNode) = new t_squad;
			(*_currentNode)->unit = interface;
			this->_n_unit++;
			return this->_n_unit;
		}
		while (current_unit < _n_unit)
		{
			if (tmpSquad->unit && tmpSquad->unit == interface) {
				std::cout << "unit already exists" << std::endl;
				return (this->_n_unit);
			}
			tmpSquad = tmpSquad->next;
			current_unit++;
		}
		(*_currentNode)->next = new t_squad;
		(*_currentNode)->next->unit = interface;
		_currentNode = &((*_currentNode)->next);
		this->_n_unit++;
		return this->_n_unit;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << e.what() << std::endl;
		return this->_n_unit;
	}
}
