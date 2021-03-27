/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:46:56 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 10:08:24 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	tryAndSign(Bureaucrat & bureaucrat, Form & form)
{
	std::cout << bureaucrat << "tries to sign " << std::endl << form;
	bureaucrat.signForm(form);
	if (!form.getSign())
	{
		std::cout << "upgrading " << bureaucrat.getName() << std::endl;
		while (bureaucrat.getGrade() > form.getSignedGrade())
			bureaucrat.upgrade();
		std::cout << bureaucrat << " tries again to sign " << std::endl << form;
		bureaucrat.signForm(form);
	}
	std::cout << form;
}

int	main()
{
	std::cout << "try:" << std::endl;
	try
	{
		std::cout << "form a(\"a\", 56, 14)" << std::endl;
		Form a("a", 56, 14);
		std::cout << "form b(\"b\", 150, 1)" << std::endl;
		Form b("b", 150, 1);
		std::cout << "form c(\"c\", 18, 21)" << std::endl;
		Form c("c", 18, 21);
		std::cout << "form d(\"d\", 0, 150)" << std::endl;
		Form d("d", 0, 150);
		std::cout << "form e(\"c\", 150, 0)" << std::endl;
		Form e("e", 150, 0);
		std::cout << "form f(\"c\", 187, 50)" << std::endl;
		Form f("f", 187, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught : " << e.what() << std::endl;
	}
	try
	{
		std::cout << "form e(\"c\", 150, 0)" << std::endl;
		Form e("e", 150, 0);
		std::cout << "form f(\"c\", 187, 50)" << std::endl;
		Form f("f", 187, 50);

	}
	catch (std::exception &e)
	{
		std::cout << "exception caught : " << e.what() << std::endl;
	}
	try
	{
		std::cout << "form f(\"c\", 187, 50)" << std::endl;
		Form f("f", 187, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught : " << e.what() << std::endl;
	}
	try
	{
		std::cout << "form g(\"c\", 87, 250)" << std::endl;
		Form f("g", 87, 250);
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught : " << e.what() << std::endl;
	}
	std::cout << "form a(\"a\", 150, 1)" << std::endl;
	Form a("a", 150, 1);
	std::cout << "form b(\"b\", 56, 14)" << std::endl;
	Form b("b", 56, 14);
	std::cout << "form c(\"c\", 18, 21)" << std::endl;
	Form c("c", 18, 21);
	std::cout << a << b << c << std::endl;

	std::cout << "Bureaucrat tom(\"Tom\", 150)" << std::endl;
	Bureaucrat 	tom("Tom", 150);

	tryAndSign(tom, a);
	std::cout << std::endl;
	tryAndSign(tom, b);
	std::cout << std::endl;
	tryAndSign(tom, c);

	return (0);
}
