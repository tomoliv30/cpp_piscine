/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:55:56 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/06 18:39:02 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "utils.hpp"
#include "Emoji.hpp"

int	main()
{
	double a[10] = {1.2, 3.4, 5.6, 6.7, 7.8, 9.10, 10.11, 11.12, 13.14, 15.16};
	float b[10] = {11.2, 13.4, 15.6, 16.7, 17.8, 19.10, 10.11, 11.12, 113.14, 115.16};
	char c[20] = "a0haha1hab89cbcbcbd";
	int	d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Emoji e[15];

	iter(a, 10, &printElement);
	std::cout << std::endl;
	iter(b, 9, &printElement);
	std::cout << std::endl;
	iter(c, 8, &printElement);
	std::cout << std::endl;
	iter(d, 7, &printElement);
	std::cout << std::endl;
	iter(e, 6, &printElement);
	std::cout << std::endl;
}
