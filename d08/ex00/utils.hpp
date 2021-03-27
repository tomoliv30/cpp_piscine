/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 14:58:20 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/09 17:19:22 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

template<typename T>
void	printContainer(T & container, std::string name, typename T::iterator end)
{
	std::cout << name << ":";
	for (typename T::iterator it = container.begin(); it != end; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

#endif
