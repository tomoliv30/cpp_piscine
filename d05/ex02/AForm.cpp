/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 21:48:55 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:16:19 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), 
				_signed(false), 
				_signedGrade(100), 
				_executeGrade(50),
				_maxGrade(1),
				_minGrade(150),
				_target("")
{
	return ;
}

AForm::AForm(std::string const & name, std::string const & target, unsigned int signedGrade, unsigned int executeGrade) :
_name(name), 
_signed(false),
_signedGrade(signedGrade),
_executeGrade(executeGrade),
_maxGrade(1),
_minGrade(150),
_target(target)
{
	if (signedGrade < _maxGrade)
		throw AForm::GradeTooHighException(name, "signed grade");
	else if (signedGrade > _minGrade)
		throw AForm::GradeTooLowException(name, "signed grade");
	else if (executeGrade > _minGrade)
		throw AForm::GradeTooLowException(name, "execute grade");
	else if (executeGrade < _maxGrade)
		throw AForm::GradeTooHighException(name, "execute grade");
}

AForm::AForm(AForm const & src) :
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

AForm	&AForm::operator=(AForm const & rhs)
{
	_target = rhs._target;
	return *this;
}

AForm::~AForm()
{
	return ;
}

std::string	const & AForm::getName() const
{
	return this->_name;
}

bool		AForm::getSign() const
{
	return this->_signed;
}

unsigned int			AForm::getSignedGrade() const
{
	return this->_signedGrade;
}

unsigned int			AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

unsigned int			AForm::getMaxGrade() const
{
	return this->_maxGrade;
}

unsigned int			AForm::getMinGrade() const
{
	return this->_minGrade;
}

std::string const & AForm::getTarget() const
{
	return this->_target;
}

void	AForm::performChecks(Bureaucrat const & executor, AForm const &form) const
{
	if (executor.getGrade() > form.getExecuteGrade())
		throw (AForm::GradeTooLowException());
	if (!form.getSign())
		throw (AForm::NotSignedException(form.getName()));
}

void		AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > getSignedGrade())
		throw (AForm::GradeTooLowException());
	this->_signed = 1;
}

std::ostream	&operator<<(std::ostream &output, AForm const &rhs)
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

AForm::GradeTooHighException::GradeTooHighException() :
_formName(""),
_type(""),
_error("")
{
	return ;
}

AForm::GradeTooHighException::GradeTooHighException(std::string const & name, std::string const & type) :
	_formName(name),
	_type(type),
	_error("AForm " + _formName + " has " + _type + " set too high")
{
	return ;
}

AForm::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

AForm::GradeTooHighException &AForm::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	_formName = rhs._formName;
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	return ;
}

const char    *AForm::GradeTooHighException::what() const throw()
{
	if (_formName == "" || _type == "")
		return "Grade too high!";
	return (_error.c_str());
}

AForm::GradeTooLowException::GradeTooLowException() :
_formName(""),
_type(""),
_error("")
{
	return ;
}

AForm::GradeTooLowException::GradeTooLowException(std::string const & name, std::string const & type) :
	_formName(name),
	_type(type),
	_error("AForm " + _formName + " has " + _type + " set too low")
{
	return ;
}

AForm::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

AForm::GradeTooLowException &AForm::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	_formName = rhs._formName;
	_type = rhs._type;
	_error = rhs._error;
	return *this;
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	return ;
}

const char    *AForm::GradeTooLowException::what() const throw()
{
	if (_formName == "" || _type == "")
		return "Grade too low!";
	return (_error.c_str());
}

AForm::NotSignedException::NotSignedException() :
	_formName(""),
	_error("")
{
}

AForm::NotSignedException::NotSignedException(NotSignedException const & src)
{
	*this = src;
}

AForm::NotSignedException::NotSignedException(std::string const & name) :
	_formName(name),
	_error(_formName + " is not signed!")
{
}

AForm::NotSignedException &AForm::NotSignedException::operator=(AForm::NotSignedException const & rhs)
{
	_formName = rhs._formName;
	_error = rhs._error;
	return *this;
}

AForm::NotSignedException::~NotSignedException() throw()
{
	return ;
}

const char    *AForm::NotSignedException::what() const throw()
{
	return _error.c_str();
}
