/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:56:28 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/06 18:28:24 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *array, unsigned int length, void (*fun)(T const &))
{
	if (!array)
		return ;
	for (unsigned int i = 0; i < length ; i++)
		if (fun)
			fun(array[i]);
}

#endif
