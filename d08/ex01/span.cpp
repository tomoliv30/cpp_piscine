/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 14:30:09 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:44:50 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>

Span::Span() : 
	_items(),
	_size(0),
	_capacity(0),
	_shortestSpan(0),
	_longestSpan(0),
	_flags(0)
{
}

Span::Span(unsigned int N) :
_items(),
_size(0),
_capacity(N),
_shortestSpan(0),
_longestSpan(0),
_flags(0)
{
}

Span::Span(const Span & src)
{
	*this = src;
}

Span &Span::operator=(Span const & rhs)
{
	_items = rhs._items;
	_size = rhs._size;
	_capacity = rhs._capacity;
	_shortestSpan = rhs._shortestSpan;
	_longestSpan = rhs._longestSpan;
	_flags = rhs._flags;
	return *this;
}

Span::~Span()
{
	return ;
}

void	Span::addNumber(int newNumber)
{
	if (_size == _capacity)
		throw (CapacityReached());
	try
	{
		_items.push_back(newNumber);
		_size++;
	}
	catch (std::exception &e)
	{
		std::cerr << "err vector push_back" << std::endl;
		throw (e);
	}
}

void	Span::addNumber(InputIterator first, InputIterator last)
{
	if (_size == _capacity)
		throw (CapacityReached());
	std::vector<int>::iterator  range = first;
	while (_size < _capacity && range != last)
	{
		range++;
		_size++;
	}
	try
	{
		_items.insert(_items.end(), first, range);
	}
	catch (std::exception &e)
	{
		std::cerr << "err inserting iterator range" << std::endl;
		throw (e);
	}
}

unsigned long Span::shortestSpan()
{
	if (_size <= 1)
		throw(NoSpan());
	std::vector<int>::const_iterator it = _items.begin();
	std::vector<int>::const_iterator end = _items.end();
	std::vector<int>::const_iterator next;
	unsigned long shortestSpan = _flags & L_SPAN ? _longestSpan : longestSpan();
	unsigned long currentSpan;
	while (it != end)
	{
		next = it;
		while (++next != end)
		{
			currentSpan = std::abs(static_cast<long>(*next) - static_cast<long>(*it));
			if (currentSpan < shortestSpan)
				shortestSpan = currentSpan;
		}
		it++;
	}
	_flags |= S_SPAN;
	return (shortestSpan);
}

unsigned long Span::longestSpan()
{
	if (_size <= 1)
		throw(NoSpan());
	if (!(_flags & L_SPAN))
		_longestSpan = std::abs(
					static_cast<long>(*std::min_element(_items.begin(), _items.end())) -
					static_cast<long>(*std::max_element(_items.begin(), _items.end()))
					);
	_flags |= L_SPAN;
	return _longestSpan;
}

void	Span::printItems(std::string const & name) const
{
	std::vector<int>::const_iterator it = _items.begin();

	std::cout << name << ":";
	while (it != _items.end())
	{
		std::cout << " " << *it;
		it++;
	}
	std::cout <<std::endl;
}

Span::CapacityReached::CapacityReached() : std::exception()
{
}

Span::CapacityReached::CapacityReached(CapacityReached const & src)
{
	*this = src;
}

Span::CapacityReached &Span::CapacityReached::operator=(CapacityReached const &)
{
	return *this;
}

Span::CapacityReached::~CapacityReached() throw()
{
}

const char    *Span::CapacityReached::what() const throw()
{
	return "Capacity Reached";
}

Span::NoSpan::NoSpan() : std::exception()
{
}

Span::NoSpan::NoSpan(NoSpan const & src)
{
	*this = src;
}

Span::NoSpan &Span::NoSpan::operator=(NoSpan const &)
{
	return *this;
}

Span::NoSpan::~NoSpan() throw()
{
}

const char    *Span::NoSpan::what() const throw()
{
	return "Span not possible";
}
