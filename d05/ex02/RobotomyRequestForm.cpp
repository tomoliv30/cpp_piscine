/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 22:16:52 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:50:38 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", "", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
}


RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	AForm::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	performChecks(executor, *this);
	static unsigned char n_call = 1;

	std::cout << "* BZZZZZZZZZZZZZZZZZZZZZZZZZZ bleep bloop blleipsd GRRRROIUSIIIIOEEEEUUUUUUUFFF *" << std::endl;
	if (n_call)
		std::cout << getTarget() << " has been robotomized succesfully." << std::endl;
	else
		std::cout << " failed to robotomize " << getTarget() << std::endl;
	n_call ^= 1;
}
