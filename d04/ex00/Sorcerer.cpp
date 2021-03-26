/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sorcerer.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:06:21 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:39:59 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()  :
	_name("undefined"),
	_title("undefined")
{
	return ;
}

Sorcerer::Sorcerer(std::string const & name, std::string const & title) :
	_name(name),
	_title(title)
{
	std::cout << getName() << " , " << getTitle() << ", is born!" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const & src) {
	*this = src;
	std::cout << getName() << " , " << getTitle() << ", is born!" << std::endl;
	return ;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs)
{
	_name = rhs.getName();
	_title = rhs.getTitle();
	return *this;
}

Sorcerer::~Sorcerer() {
	std::cout << getName() << " , " << getTitle() << ", is dead. Consequences will never be the same!" << std::endl;
	return ;
}

std::string const & Sorcerer::getName() const {
	return this->_name;
}

std::string const & Sorcerer::getTitle() const {
	return this->_title;
}

std::ostream &operator<<(std::ostream &output, Sorcerer const &rhs){
	output << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies!" << std::endl;
	return (output);
}

void	Sorcerer::polymorph(Victim const &victim) const {
	victim.getPolymorphed();
}
