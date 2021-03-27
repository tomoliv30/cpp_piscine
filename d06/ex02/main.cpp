/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:16:53 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:40:54 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"

#include <math.h>
#include <iostream>

Base	*generateA(void)
{
	return reinterpret_cast<Base *>(new A());
}

Base	*generateB(void)
{
	return reinterpret_cast<Base *>(new B());
}

Base	*generateC(void)
{
	return reinterpret_cast<Base *>(new C());
}


Base	*generate(void)
{
	Base	*(*generator[3])(void) = {&generateA, &generateB, &generateC};

	return generator[rand() % 3]();
}

void	identify_from_pointer(Base * p)
{
	A *testA = dynamic_cast<A *>(p);
	B *testB = dynamic_cast<B *>(p);
	C *testC = dynamic_cast<C *>(p);

	if (testA)
		std::cout << "A" << std::endl;
	else if (testB)
		std::cout << "B" << std::endl;
	else if (testC)
		std::cout << "C" << std::endl;
}

void	identify_from_reference(Base & p)
{
	unsigned int	result = 0;
	std::string type[3] = {"A", "B", "C"};

	try
	{
		A &testA = dynamic_cast<A &>(p);
		static_cast<void>(testA);
		result = 0;
	}
	catch (std::exception &)
	{
	}
	try
	{
		B &testB = dynamic_cast<B &>(p);
		static_cast<void>(testB);
		result = 1;
	}
	catch (std::exception &)
	{
	}
	try
	{
		C &testC = dynamic_cast<C &>(p);
		static_cast<void>(testC);
		result = 2;
	}
	catch (std::exception &)
	{
	}
	std::cout << type[result] << std::endl;
}

int	main()
{
	srand(time(NULL));
	Base *base;

	for (unsigned int i = 0; i < 15; i++) {
		std::cout << "base = generate()" << std::endl;
		base = generate();
		std::cout << "id from pointer" << std::endl;
		identify_from_pointer(base);
		std::cout << "id from ref" << std::endl;
		identify_from_reference(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}
