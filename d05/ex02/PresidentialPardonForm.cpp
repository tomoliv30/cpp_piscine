/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 22:27:04 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:47:31 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", "", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
}


PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	AForm::operator=(rhs);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	performChecks(executor, *this);
	std::cout << getTarget() << " has been pardonned by Zafod Beeblebrox."<< std::endl;
}
