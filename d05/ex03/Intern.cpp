/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 00:11:13 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 11:19:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	_forms[0] = &Intern::_newPresidentialPardonForm;
	_forms[1] = &Intern::_newRobotomyRequestForm;
	_forms[2] = &Intern::_newShrubberyCreationForm;
	_forms[3] = NULL;
	_validInput[0] = "presidential pardon request";
	_validInput[1] = "robotomy request";
	_validInput[2] = "shrubbery request";
}

Intern::Intern(Intern const &)
{
	return ;
}

Intern	&Intern::operator=(Intern const &)
{
	return *this;
}

Intern::~Intern()
{
}

Intern::FormNotFoundException::FormNotFoundException()
{
	return ;
}

Intern::FormNotFoundException::FormNotFoundException(const FormNotFoundException &src)
{
	*this = src;
}

Intern::FormNotFoundException &Intern::FormNotFoundException::operator=(const FormNotFoundException & )
{
	return *this;
}

Intern::FormNotFoundException::~FormNotFoundException(void) throw()
{
	return ;
}

const char    *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	int	parse;

	try
	{
		parse = _parseInput(formName);
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create " << formName << ", " << e.what() << std::endl;
		throw (Intern::FormNotFoundException());
	}
	std::cout<< "Intern creates " << formName << " form." << std::endl;
	return ((this->*_forms[parse])(target));
}


Form *Intern::_newPresidentialPardonForm(std::string target)
{
	return  new PresidentialPardonForm(target);
}

Form *Intern::_newRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::_newShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

int	Intern::_parseInput(std::string formName)
{
	int	index = 0;

	while (index < 3)
	{
		if (_validInput[index] == formName)
			return (index);
		index++;
	}
	throw (Intern::FormNotFoundException());
}
