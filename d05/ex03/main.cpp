/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 00:35:58 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:22:20 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


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

void	tryAndExecute(Bureaucrat & bureaucrat, Form & form)
{
	std::cout << bureaucrat << "tries to execute " << std::endl << form;
	bureaucrat.executeForm(form);
	if (!form.getSign())
	{
		std::cout << "upgrading " << bureaucrat.getName() << std::endl;
		while (bureaucrat.getGrade() > form.getExecuteGrade())
			bureaucrat.upgrade();
		std::cout << bureaucrat << " tries again to execute" << std::endl << form;
		bureaucrat.executeForm(form);
	}
	else if (bureaucrat.getGrade() > form.getExecuteGrade())
	{
		std::cout << "upgrading " << bureaucrat.getName() << std::endl;
		while (bureaucrat.getGrade() > form.getExecuteGrade())
			bureaucrat.upgrade();
		std::cout << bureaucrat << " tries again to execute" << std::endl << form;
		bureaucrat.executeForm(form);
	}
}

int	main()
{
	Intern someRandomIntern;

	Form	*a;
	Form	*b;
	Form	*c;
	Form	*d;
	Form	*e;

	try 
	{
		a = someRandomIntern.makeForm("shrubbery request", "target1");
		b = someRandomIntern.makeForm("robotomy request", "target2");
		c = someRandomIntern.makeForm("presidential pardon request", "target3");
		d = someRandomIntern.makeForm("presidential pardon", "target4");
	}
	catch (std::exception &e)
	{
		std::cout << "caught something e.what() --> " << e.what() << std::endl;
	}
	try 
	{
		e = someRandomIntern.makeForm("", "");
	}
	catch (std::exception &e)
	{
		std::cout << "caught something e.what() --> " << e.what() << std::endl;
	}

	std::cout << "\n\tsame tests as last exercise with newly created forms\n" << std::endl;


	Bureaucrat tom("tom", 140);


	tryAndExecute(tom, *a);
	std::cout << std::endl;
	tryAndExecute(tom, *b);
	std::cout << std::endl;
	tryAndExecute(tom, *c);
	std::cout << std::endl;

	std::cout << "\t\t so he needs to sign them first...\n" << std::endl;
	std::cout << "downgrading tom...\n" << std::endl;
	while (tom.getGrade() < tom.getMinGrade()) {
		tom.downgrade();
	}

	tryAndSign(tom, *a);
	std::cout << std::endl;
	tryAndSign(tom, *b);
	std::cout << std::endl;
	tryAndSign(tom, *c);

	std::cout << "\t\t to be able to execute them...\n" << std::endl;
	std::cout << "downgrading tom...\n" << std::endl;
//
	while (tom.getGrade() < tom.getMinGrade()) {
		tom.downgrade();
	}

	tryAndExecute(tom, *a);
	std::cout << std::endl;
	tryAndExecute(tom, *b);
	std::cout << std::endl;
	tryAndExecute(tom, *c);
	std::cout << std::endl;

	std::cout << "robotomy stuff 50 % of the time.." << std::endl;
	tryAndExecute(tom, *b);
	std::cout << std::endl;
	tryAndExecute(tom, *b);
	std::cout << std::endl;
	tryAndExecute(tom, *b);
	std::cout << std::endl;
	tryAndExecute(tom, *b);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	return (0);
}
