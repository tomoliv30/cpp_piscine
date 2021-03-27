/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Emoji.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 17:06:08 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:37:29 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Emoji.hpp"

Emoji::Emoji()
	: _emoji("") 
{}

Emoji::Emoji( std::string const & emoji) 
	: _emoji(emoji) 
{}

Emoji::Emoji(Emoji const & src) 
{
	*this = src;
}

Emoji &Emoji::operator=(Emoji const & rhs)
{
	_emoji = rhs.getEmoji();
	return *this;
}

Emoji::~Emoji()
{
}

bool Emoji::operator>(Emoji const & rhs )
{ 
	return (this->_emoji > rhs._emoji); 
}
bool Emoji::operator<(Emoji const & rhs )
{ 
	return (this->_emoji < rhs._emoji); 
}
std::string const & Emoji::getEmoji() const
{
	return _emoji;
}

std::ostream &operator<<(std::ostream & out, Emoji const & src)
{
	out << src.getEmoji();
	return (out);
}
