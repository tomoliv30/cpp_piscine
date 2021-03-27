/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 13:38:39 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 10:56:32 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : 
	_name("default"), 
	_grade(150), 
	_maxGrade(1), 
	_minGrade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :
	_name(name), 
	_grade(grade), 
	_maxGrade(1), 
	_minGrade(150)
{
	if (grade > this->_minGrade)
		throw(GradeTooLowException());
	else if (grade < this->_maxGrade)
		throw(GradeTooHighException());
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this =  src;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src._grade;
	this->_maxGrade = src._maxGrade;
	this->_minGrade = src._minGrade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

unsigned int			Bureaucrat::getMinGrade() const
{
		return _minGrade;
}

unsigned int			Bureaucrat::getMaxGrade() const
{
		return _maxGrade;
}

void		Bureaucrat::downgrade()
{
	if (_grade + 1 > this->_minGrade)
	{
		throw (GradeTooLowException());
		return ;
	}
	this->_grade++;

}

void		Bureaucrat::upgrade()
{
	if (_grade - 1 < this->_maxGrade)
	{
		throw (GradeTooHighException());
		return ;
	}
	this->_grade--;
}

void					Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << _name << " cannot sign form " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signs form " << form.getName() << std::endl;
}

void					Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << _name << " cannot execute form " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " executes form " << form.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &output, Bureaucrat const & rhs)
{
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ". min grade: " << rhs.getMinGrade() << ", max grade: " << rhs.getMaxGrade() << std::endl;
	return output;
}


Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException  &Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &)
{
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char    *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &)
{
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

const char    *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}
