/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:53:26 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/06 18:32:06 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T & x, T & y)
{
	T	swap = x;

	x = y;
	y = swap;
}

template<typename T>
T min(T & x, T & y)
{
	return (x < y ? x : y);
}

template<typename T>
T max(T & x, T & y)
{
	return (x > y ? x : y);
}

#endif
