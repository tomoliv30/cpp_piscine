/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 14:03:52 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:40:40 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <algorithm>

class	ItemNotFound : public std::exception
{
	public:
		ItemNotFound();
		ItemNotFound(ItemNotFound const & src);
     	ItemNotFound &operator= (ItemNotFound const & rhs);
		virtual ~ItemNotFound() throw();
     	virtual const char    *what() const throw();
};

template<typename T>
typename T::iterator easyFind(T & container, int toFind)
{
	typename T::iterator	end;
	typename T::iterator	first;

	end = container.end();
	first = std::find(container.begin(), end, toFind);
	if (first == end)
		throw (ItemNotFound());
	return first;
}

#endif
