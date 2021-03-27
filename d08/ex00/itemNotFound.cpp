/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 14:10:52 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:41:17 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

ItemNotFound::ItemNotFound() : std::exception()
{
	return ;
}

ItemNotFound::ItemNotFound(ItemNotFound const & src)
{
	*this = src;
}

ItemNotFound &ItemNotFound::operator=(ItemNotFound const &)
{
	return *this;
}

ItemNotFound::~ItemNotFound() throw()
{
	return ;
}

const char    *ItemNotFound::what() const throw()
{
	return ("Item not found");
}
