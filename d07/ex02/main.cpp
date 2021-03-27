/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 12:19:06 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:39:02 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Emoji.hpp"
#include <stdlib.h>

int	main()
{
	std::cout << "<int>a" << std::endl;
	Array<int> a;
	std::cout << "<float>b(0)" << std::endl;
	Array<float> b(0);
	std::cout << "<double>c(25)" << std::endl;
	Array<double> c(25);
	std::cout << "<char>d(1)" << std::endl;
	Array<char> d(1);
	std::cout << "<Emoji>e(10)" << std::endl;
	Array<Emoji> e(10);
	try
	{
		std::cout << "<int>f(-1)" << std::endl;
		Array<int> f(-1);
		std::cout << f[15] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught something e.what() " << e.what() << std::endl;
	}
	a.printArray("a");
	b.printArray("b");
	c.printArray("c");
	d.printArray("d");
	e.printArray("e");
	std::cout << "a.size()=" << a.size() 
		<< " b.size()="<< b.size() 
		<< " c.size()="<< c.size() 
		<< " d.size()="<< d.size() 
		<< " e.size()="<< e.size() << std::endl;
	try
	{
		std::cout << "a[0] " << a[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught something e.what() " << e.what() << std::endl;
	}

	try
	{
		std::cout << "a[10]" << a[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught something e.what() " << e.what() << std::endl;
	}
	try
	{
		std::cout << "b[10]" << b[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "caught something e.what() " << e.what() << std::endl;
	}
	try
	{
		std::cout << "c[14]" << c[14] << std::endl
				<< "d[1]" << d[0] << std::endl
				<< "e[5]" << e[5] << std::endl
				<< "e[0]" << e[0] << std::endl
				<< "e[-1]" << e[-1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "caught something e.what() " << e.what() << std::endl;
	}

	std::cout << "construction by assignment" << std::endl;


	std::cout << "Array<int> a1(a); \n\
	Array<float> b1(b); \n\
	Array<double> c1(c); \n\
	Array<char> d1(d); \n\
	Array<Emoji> e1(e);" << std::endl;

	Array<int> a1(a);
	Array<float> b1(b);
	Array<double> c1(c);
	Array<char> d1(d);
	Array<Emoji> e1(e);

	a.printArray("a");
	a1.printArray("a1");
	b.printArray("b");
	b1.printArray("b1");
	c.printArray("c");
	c1.printArray("c1");
	d.printArray("d");
	d1.printArray("d1");
	e.printArray("e");
	e1.printArray("e1");


	std::cout << "changing values in c d e" << std::endl;
	c[10] = 9.4;
	c[2] = 129.4;
	d[0] = 'a';
	e[3] = Emoji("\\ (•◡•) /");
	e[0] = Emoji("\\ (•◡•) /");
	e[0] = Emoji("ʕ•ᴥ•ʔ");

	c.printArray("c");
	c1.printArray("c1");
	d.printArray("d");
	d1.printArray("d1");
	e.printArray("e");
	e1.printArray("e1");

	std::cout << "copying a, b, c, d, e into a1, b1, c1, d1, e1" << std::endl;
	a1 = a;
	b1 = b;
	c1 = c;
	d1 = d;
	e1 = e;

	a.printArray("a");
	a1.printArray("a1");
	b.printArray("b");
	b1.printArray("b1");
	c.printArray("c");
	c1.printArray("c1");
	d.printArray("d");
	d1.printArray("d1");
	e.printArray("e");
	e1.printArray("e1");

	std::cout << "changing values in c1 d1 e1" << std::endl;
	c1[10] = 109.4;
	c1[2] = 19.867;
	d1[0] = 'b';
	e1[3] = Emoji("(ง'̀-'́)ง");
	e1[0] = Emoji("ಠ╭╮ಠ");
	e1[0] = Emoji("◉_◉");

	c.printArray("c");
	c1.printArray("c1");
	d.printArray("d");
	d1.printArray("d1");
	e.printArray("e");
	e1.printArray("e1");

	std::cout << "sized array into  empty array" << std::endl;
	std::cout << "Array<Emoji> f1(15)" << std::endl;
	Array<Emoji> f1(15);
	std::cout << "Array<Emoji> f" << std::endl;
	Array<Emoji> f;

	std::cout << "calling printArray on f f1" << std::endl;
	f.printArray("f");
	f1.printArray("f1");
	std::cout << "f = f1" << std::endl;
	f = f1;
	std::cout << "calling printArray on f f1" << std::endl;
	f.printArray("f");
	f1.printArray("f1");
	std::cout << "changing values in f1" << std::endl;
	f1[3] = Emoji("(ง'̀-'́)ง");
	f1[0] = Emoji("ಠ╭╮ಠ");
	f1[0] = Emoji("◉_◉");
	std::cout << "calling printArray on f f1" << std::endl;
	f.printArray("f");
	f1.printArray("f1");

	std::cout << "empty array into  sized array" << std::endl;
	std::cout << "Array<Emoji> f2" << std::endl;
	Array<Emoji> f2;
	std::cout << "f1 = f2" << std::endl;
	f1 = f2;
	std::cout << "calling printArray on f f1 f2" << std::endl;
	f.printArray("f");
	f1.printArray("f1");
	f2.printArray("f2");

	//system("leaks ex02");
	return (0);
}
