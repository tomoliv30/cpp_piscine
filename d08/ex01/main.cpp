/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 14:31:45 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/09 17:43:00 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <limits.h>


int	generator()
{
	return (rand());
}

int	generator_30()
{
	return (rand() % 30);
}

void	populate(int & n)
{
	n = 5;
}

void	print(int toPrint)
{
	std::cout << toPrint << std::endl;
}

int	main()
{
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}

	srand(time(NULL));
	std::vector<int> ints_20(20);
	std::vector<int> ints_10(10);
	std::generate(ints_20.begin(), ints_20.end(), generator);
	std::cout << "--random ints--" << std::endl;
	std::for_each(ints_20.begin(), ints_20.end(), print);
	std::cout << "Span b(10)" << std::endl;
	Span b(10);
	Span c(10);
	std::cout << "calling addNumber(ints.begin(), ints.end())" << std::endl;
	b.addNumber(ints_20.begin(), ints_20.end());
	b.printItems("b");
	std::cout << "test capacity:";
	try
	{
		std::cout << "b.addNumber(10)" << std::endl;
		b.addNumber(10);
	}
	catch(std::exception &e)
	{
		std::cout << "e caught e.what-> " << e.what() << std::endl;

	}
	try
	{
		std::cout << "b.addNumber(ints.begin(), ints.end())" << std::endl;
		b.addNumber(ints_20.begin(), ints_20.end());
	}
	catch(std::exception &e)
	{
		std::cout << "e caught e.what-> " << e.what() << std::endl;

	}

	std::cout << "longest span: " << b.longestSpan() << std::endl;
	std::cout << "shortest span: " << b.shortestSpan() << std::endl;

	std::cout << "--ints, negative/positive--" << std::endl;
	std::generate(ints_10.begin(), ints_10.end(), generator_30);
	ints_10[1] *= -1;
	ints_10[3] *= -1;
	ints_10[7] *= -1;
	ints_10[9] *= -1;
	c.addNumber(ints_10.begin(), ints_10.end());
	c.printItems("c");

	std::cout << "longest span: " << c.longestSpan() << std::endl;
	std::cout << "shortest span: " << c.shortestSpan() << std::endl;

	std::cout << "same number" << std::endl;

	Span d(5);

	d.addNumber(5);
	d.addNumber(5);
	d.addNumber(5);
	d.addNumber(5);
	d.addNumber(5);
	d.printItems("d");

	std::cout << "longest span: " << d.longestSpan() << std::endl;
	std::cout << "shortest span: " << d.shortestSpan() << std::endl;

	std::cout << "biggest biggest span" << std::endl;

	Span e(5);

	e.addNumber(INT_MIN);
	e.addNumber(-5);
	e.addNumber(35);
	e.addNumber(INT_MAX);
	e.addNumber(5);
	e.printItems("e");

	std::cout << "longest span: " << e.longestSpan() << std::endl;
	std::cout << "shortest span: " << e.shortestSpan() << std::endl;

	Span f(5);

	f.addNumber(INT_MIN);
	f.addNumber(INT_MAX);
	f.printItems("f");

	std::cout << "longest span: " << f.longestSpan() << std::endl;
	std::cout << "shortest span: " << f.shortestSpan() << std::endl;

	Span g(5);

	g.addNumber(INT_MIN);
	g.addNumber(0);
	g.addNumber(INT_MAX);
	g.printItems("g");

	std::cout << "longest span: " << g.longestSpan() << std::endl;
	std::cout << "shortest span: " << g.shortestSpan() << std::endl;

	std::cout << "test exception" << std::endl;

	Span h(5);
	h.printItems("h");
	try
	{
		std::cout << "longest span: " << h.longestSpan() << std::endl;
		std::cout << "shortest span: " << h.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "e caught e.what-> " << e.what() << std::endl;
	}
	h.addNumber(3);
	h.printItems("h");
	try
	{
		std::cout << "shortest span: " << h.shortestSpan() << std::endl;
		std::cout << "longest span: " << h.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "e caught e.what-> " << e.what() << std::endl;
	}
	h.addNumber(INT_MIN);
	h.printItems("h");
	try
	{
		std::cout << "shortest span: " << h.shortestSpan() << std::endl;
		std::cout << "longest span: " << h.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "e caught e.what-> " << e.what() << std::endl;
	}
	std::cout << "test with 1234 numbers" << std::endl;
	std::vector<int> oi(1234);

	std::generate(oi.begin(), oi.end(), generator);
	Span i(2002);

	i.addNumber(oi.begin(), oi.end());

	std::cout << "shortest span: " << i.shortestSpan() << std::endl;
	std::cout << "longest span: " << i.longestSpan() << std::endl;

	return (0);
}
