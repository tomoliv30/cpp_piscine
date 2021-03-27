/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 00:42:46 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:19:42 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), 
				_signed(false), 
				_signedGrade(100), 
				_executeGrade(50),
				_maxGrade(1),
				_minGrade(150),
				_target("")
{
	return ;
}

Form::Form(std::string const & name, std::string const & target, unsigned int signedGrade, unsigned int executeGrade) :
_name(name), 
_signed(false),
_signedGrade(signedGrade),
_executeGrade(executeGrade),
_maxGrade(1),
_minGrade(150),
_target(target)
{
	if (signedGrade < _maxGrade)
		throw Form::GradeTooHighException(name, "signed grade");
	else if (signedGrade > _minGrade)
		throw Form::GradeTooLowException(name, "signed grade");
	else if (executeGrade > _minGrade)
		throw Form::GradeTooLowException(name, "execute grade");
	else if (executeGrade < _maxGrade)
		throw Form::GradeTooHighException(name, "execute grade");
}

Form::Form(Form const & src) :
_name(src._name), 
_signed(false),
_signedGrade(src._signedGrade),
_executeGrade(src._executeGrade),
_maxGrade(1),
_minGrade(150),
_target(src._target)
{
	return ;
}

Form	&Form::operator=(Form const & rhs)
{
	_target = rhs._target;
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

std::string Form::getTarget() const
{
	return this->_target;
}

void	Form::performChecks(Bureaucrat const & executor, Form const &form) const
{
	if (executor.getGrade() > form.getExecuteGrade())
		throw (Form::GradeTooLowException());
	if (!form.getSign())
		throw (Form::NotSignedException(form.getName()));
}

void		Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > getSignedGrade())
		throw (Form::GradeTooLowException());
	this->_signed = 1;
}

std::ostream	&operator<<(std::ostream &output, Form const &rhs)
{
	output << "Form name: " << rhs.getName() 
		<< (rhs.getSign() ? ", signed" : ", not signed")
		<< ", target: " << rhs.getTarget()
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

Form::GradeTooHighException::GradeTooHighException(std::string name, std::string type) :
	_formName(name),
	_type(type),
	_error("Form " + _formName + " has " + _type + " set too high")
{
	return ;
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
	*this = src;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const GradeTooHighException & rhs)
{
	_formName = rhs._formName;
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
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

Form::GradeTooLowException::GradeTooLowException(std::string name, std::string type) :
	_formName(name),
	_type(type),
	_error("Form " + _formName + " has " + _type + " set too low")
{
	return ;
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
	*this = src;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const GradeTooLowException & rhs)
{
	_formName = rhs._formName;
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

const char    *Form::GradeTooLowException::what() const throw()
{
	if (_formName == "" || _type == "")
		return "Grade too low!";
	return (_error.c_str());
}

Form::NotSignedException::NotSignedException() :
	_formName(""),
	_error("")
{
}

Form::NotSignedException::NotSignedException(const NotSignedException &src)
{
	*this = src;
}

Form::NotSignedException &Form::NotSignedException::operator=(const Form::NotSignedException &rhs)
{
	_formName = rhs._formName;
	_error = rhs._error;
	return *this;
}

Form::NotSignedException::NotSignedException(std::string name) :
	_formName(name),
	_error(_formName + " is not signed!")
{
}

Form::NotSignedException::~NotSignedException(void) throw()
{
	return ;
}

const char    *Form::NotSignedException::what() const throw()
{
	return _error.c_str();
}
