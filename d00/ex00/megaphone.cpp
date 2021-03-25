/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:29:03 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 09:48:03 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)  {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; av[i] ; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (isprint(av[i][j]))
				std::cout << static_cast<char>(toupper(av[i][j]));
		}
		}
	std::cout << std::endl;
	return 0;
}
