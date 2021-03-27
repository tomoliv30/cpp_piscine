/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Scalar.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 13:38:17 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/04 10:28:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

Scalar::Scalar() :
	_input(""),
	_raw(0),
	_endptr(NULL),
	_flags(0),
	_precision(0)
{
	return ;
}

Scalar::Scalar(char const *input) :
	_input(setInput(input)),
	_raw(std::strtod(input, &_endptr)),
	_flags(setFlags()),
	_precision(setPrecision())
{
	if ((_flags >> IS_CHAR) & 1)
	{
		_raw = input[0];
	}
	return ;
}

Scalar::Scalar(Scalar const & src)
{
	*this = src;
}

Scalar	&Scalar::operator=(Scalar const & src)
{
	_raw = src._raw;
	_input = src._input;
	_endptr = src._endptr;
	_flags = src._flags;
	_precision = src._precision;
	return *this;
}

Scalar::~Scalar()
{
	return ;
}

Scalar::nonDisplayable::nonDisplayable()
{
	return ;
}

Scalar::nonDisplayable::nonDisplayable(nonDisplayable const & src)
{
	*this = src;
}

Scalar::nonDisplayable &Scalar::nonDisplayable::operator=(nonDisplayable const &)
{
	return *this;
}

const char *Scalar::nonDisplayable::what() const throw()
{
	return "Non displayable";
}

Scalar::nonDisplayable::~nonDisplayable() throw()
{
}

Scalar::impossibleConversion::impossibleConversion()
{
	return ;
}

Scalar::impossibleConversion::impossibleConversion(impossibleConversion const & src)
{
	*this = src;
	return ;
}


Scalar::impossibleConversion &Scalar::impossibleConversion::operator=(impossibleConversion const &)
{
	return *this;
}

const char *Scalar::impossibleConversion::what() const throw()
{
	return "impossible";
}

Scalar::impossibleConversion::~impossibleConversion() throw()
{
	return ;
}


bool	Scalar::validInput()
{
	return (!*_endptr 
			|| !strcmp(_endptr, "f") 
			|| (*_endptr && _input.length() == 1));
}

unsigned char Scalar::setFlags()
{
	unsigned char	flags = 0;

	flags |= (_input == "nan" | _input == "nanf") << IS_NAN;
	flags |= ( _input == "+inff"
				| _input == "-inff"
				| _input == "inf"
				| _input == "inff"
				| _input == "+inf"
				| _input == "-inf") << IS_INF;
	flags |= (_input.length() == 1 && !isdigit(_input[0])) << IS_CHAR;
	flags |= ((errno == ERANGE) << OVERFLOW);
	flags |= ((_input.find("f") != std::string::npos) << FLOAT_FORMAT);
	return (flags);
}

int		Scalar::setPrecision()
{
	size_t	dec = _input.find(".");

	if (dec == std::string::npos)
		return 1;
	return _input.length() - dec - 1 - (_flags >> FLOAT_FORMAT & 1);
}

std::string Scalar::setInput(char const *input)
{
	std::string newInput;

	newInput.assign(input);
	return (newInput);
}

void	Scalar::debug()
{
	std::cout << std::endl << "raw: " << _raw << std::endl <<  "_endptr: " << _endptr <<std::endl << " precision: " << _precision << std::endl
		<< " input: " << _input << std::endl
		<< "flags :char: " << (_flags & IS_CHAR)
		<< " nan: " << (_flags >> IS_NAN & 1)
		<< " inf: " << (_flags >> IS_INF & 1)
		<< " overflow: " << (_flags >> OVERFLOW & 1) 
		<< " f: " << (_flags >> FLOAT_FORMAT & 1) << std::endl << std::endl;
}
