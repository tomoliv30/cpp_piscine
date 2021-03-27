/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 22:51:53 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:50:13 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

void	tryAndSign(Bureaucrat & bureaucrat, AForm & form)
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

void	tryAndExecute(Bureaucrat & bureaucrat, AForm & form)
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
	ShrubberyCreationForm a("target1");
	RobotomyRequestForm b("target2");
	PresidentialPardonForm c("target3");

	Bureaucrat tom("tom", 140);


	tryAndExecute(tom, a);
	std::cout << std::endl;
	tryAndExecute(tom, b);
	std::cout << std::endl;
	tryAndExecute(tom, c);
	std::cout << std::endl;

	std::cout << "\t\t so he needs to sign them first...\n" << std::endl;
	std::cout << "downgrading tom...\n" << std::endl;
	while (tom.getGrade() < tom.getMinGrade()) {
		tom.downgrade();
	}

	tryAndSign(tom, a);
	std::cout << std::endl;
	tryAndSign(tom, b);
	std::cout << std::endl;
	tryAndSign(tom, c);

	std::cout << "\t\t to be able to execute them...\n" << std::endl;
	std::cout << "downgrading tom...\n" << std::endl;
	//
	while (tom.getGrade() < tom.getMinGrade()) {
		tom.downgrade();
	}

	tryAndExecute(tom, a);
	std::cout << std::endl;
	tryAndExecute(tom, b);
	std::cout << std::endl;
	tryAndExecute(tom, c);
	std::cout << std::endl;

	std::cout << "robotomy stuff 50% of the time.." << std::endl;
	tryAndExecute(tom, b);
	std::cout << std::endl;
	tryAndExecute(tom, b);
	std::cout << std::endl;
	tryAndExecute(tom, b);
	std::cout << std::endl;
	tryAndExecute(tom, b);
	std::cout << std::endl;

	return (0);
}
