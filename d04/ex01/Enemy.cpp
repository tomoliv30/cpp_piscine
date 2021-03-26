/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Enemy.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:28:52 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 15:32:56 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()  :
	_type("default"),
	_hp(0)
{
	std::cout << "note: hp was set to 0" << std::endl;
	return ;
}

Enemy::Enemy(int hp, std::string const & type)  :
	_type(type),
	_hp(hp < 0 ? 0 : hp)
{
	if (!_hp)
		std::cout << "\tnote: hp was set to 0 for Enemy " << type << std::endl;
	return ;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return ;
}

Enemy &Enemy::operator=(Enemy const &rhs)
{
	this->_hp = rhs._hp;
	return *this;
}

Enemy::~Enemy() 
{
	return ;
}

std::string const  & Enemy::getType() const 
{
	return this->_type;
}

int Enemy::getHP() const 
{
	return this->_hp;
}

void	Enemy::takeDamage(int damage) 
{
	if (damage <= 0)
		return ;
	if (!_hp)
	{
		std::cout << "Enemy " << getType() << " cannot take more damage!" << std::endl;
		return ;
	}
	if (damage > _hp)
		damage = _hp;
	_hp -= damage;
	std::cout << "Enemy " << getType() << " takes "  << damage << " points damage!" << std::endl;
}

void	Enemy::setHP(int hp)
{
	this->_hp = hp < 0 ? 0 : hp;
}
