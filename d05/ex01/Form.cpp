/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 16:37:47 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:10:26 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), 
				_signed(false), 
				_signedGrade(100), 
				_executeGrade(50),
				_maxGrade(1),
				_minGrade(150)
{
	return ;
}

Form::Form(std::string const & name, unsigned int const signedGrade, unsigned int const executeGrade) :
_name(name), 
_signed(false),
_signedGrade(signedGrade),
_executeGrade(executeGrade),
_maxGrade(1),
_minGrade(150)
{
	if (signedGrade < _maxGrade)
		throw Form::GradeTooHighException(name, "signed grade");
	else if (signedGrade > _minGrade)
		throw Form::GradeTooLowException(name, "signed grade");
	else if (executeGrade < _maxGrade)
		throw Form::GradeTooHighException(name, "execute grade");
	else if (executeGrade > _minGrade)
		throw Form::GradeTooLowException(name, "execute grade");
}

Form::Form(Form const & src) :
_name(src._name), 
_signed(src.getSign()),
_signedGrade(src.getSignedGrade()),
_executeGrade(src.getExecuteGrade()),
_maxGrade(1),
_minGrade(150)
{
	return ;
}

Form	&Form::operator=(Form const &)
{
	return *this;
}

Form::~Form()
{
	return ;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool		Form::getSign() const
{
	return this->_signed;
}

unsigned int			Form::getSignedGrade() const
{
	return this->_signedGrade;
}

unsigned int			Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

unsigned int			Form::getMaxGrade() const
{
	return this->_maxGrade;
}

unsigned int			Form::getMinGrade() const
{
	return this->_minGrade;
}

void		Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > getSignedGrade())
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &output, Form const &rhs)
{
	output << "Form name: " << rhs.getName() 
		<< (rhs.getSign() ? ", signed" : ", not signed")
		<< ", grade to sign: " << rhs.getSignedGrade()
		<< ", grade to execute: " << rhs.getExecuteGrade()
		<< ", min grade: " << rhs.getMinGrade()
		<< ", max grade: " << rhs.getMaxGrade()
		<< std::endl;
	return output;
}

Form::GradeTooHighException::GradeTooHighException() :
_formName(""),
_type(""),
_error("")
{
	return ;
}

Form::GradeTooHighException::GradeTooHighException(std::string const & name, std::string const & type) :
	_formName(name),
	_type(type),
	_error("Form " + _formName + " has " + _type + " set too high")
{
	return ;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) :
	_formName(src._formName),
	_type(src._type),
	_error(src._error)
{
	return ;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	_formName = rhs._formName;
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	return ;
}

const char    *Form::GradeTooHighException::what() const throw()
{
	if (_formName == "" || _type == "")
		return "Grade too high!";
	return (_error.c_str());
}

Form::GradeTooLowException::GradeTooLowException() :
_formName(""),
_type(""),
_error("")
{
	return ;
}

Form::GradeTooLowException::GradeTooLowException(std::string const & name, std::string const & type) :
	_formName(name),
	_type(type),
	_error("Form " + _formName + " has " + _type + " set too low")
{
	return ;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) :
	_formName(src._formName),
	_type(src._type),
	_error(src._error)
{
	return ;
}

Form::GradeTooLowException  &Form::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	_formName = rhs._formName;
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	return ;
}

const char    *Form::GradeTooLowException::what() const throw()
{
	if (_formName == "" || _type == "")
		return ("Grade too low!");
	return _error.c_str();
}
