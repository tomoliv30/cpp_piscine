/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 14:15:28 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/09 18:35:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "utils.hpp"
#include <list>
#include <vector>
#include <stack>
#include <limits.h>

enum e_values
{
	V1 = 1,
	V2,
	V3,
	V4,
	V5,
	V6,
	V7,
	V8,
	V9
};

int	main()
{
	int	ints[] = 
	{
		V1, V2, V3, V4, V5, V6, V7, V8, V9,
		V2, V1, V2, V3, V4, V5, V6, V7, V8,
		V3, V2, V1, V2, V3, V4, V5, V6, V7,
		V4, V3, V2, V1, V2, V3, V4, V5, V6,
		V5, V4, V3, V2, V1, V2, V3, V4, V5,
	};

	int	invalid[] =
	{
		INT_MIN, INT_MAX, 0, -1, -1230984, 10
	};

	std::vector<int> v(ints, ints + sizeof(ints) /sizeof(int));
	std::list<int> l(ints, ints + sizeof(ints) /sizeof(int));
	std::deque<int> d(l.begin(), l.end());
	std::vector<int> e; //empty

	std::cout << "in empty container e" << std::endl;

	try
	{
		printContainer(e, "e", easyFind(e, 29));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	printContainer(v, "vector<int> v", v.end());
	printContainer(l, "list<int> l", l.end());
	printContainer(d, "deque<int> d", d.end());

	for (int i = 0; i < ints[i]; i++)
	{
		std::cout << "print until first occurence of " << ints[i]<<std::endl;
		printContainer(v, "v", easyFind(v, ints[i]));
		printContainer(l, "l", easyFind(l, ints[i]));
		printContainer(d, "d", easyFind(d, ints[i]));
	}
	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < sizeof(invalid) / sizeof(int); i++)
	{
		std::cout << "print until first occurence of " << invalid[i] << std::endl ;
		try
		{
			std::cout << "in vector" << std::endl;
			printContainer(v, "v", easyFind(v, invalid[i]));
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "in list" << std::endl;
			printContainer(l, "l", easyFind(l, invalid[i]));
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "in deque" << std::endl;
			printContainer(d, "d", easyFind(d, invalid[i]));
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
