/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Scalar.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 13:38:34 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:30:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>

enum e_flags
{
	IS_CHAR = 1,
	IS_NAN = 2,
	IS_INF = 3,
	OVERFLOW = 4,
	FLOAT_FORMAT = 5
};

class Scalar
{
	private:
		std::string 	_input;
		double			_raw;
		char			*_endptr;
		unsigned char	_flags;
		int				_precision;
		class nonDisplayable : public std::exception
		{
			public:
				nonDisplayable();
				nonDisplayable(nonDisplayable const & src);
				nonDisplayable &operator=(nonDisplayable const & src);
				virtual ~nonDisplayable() throw();
				virtual const char *what() const throw();
		};
		class impossibleConversion: public std::exception
		{
			public:
				impossibleConversion();
				impossibleConversion(impossibleConversion const & src);
				impossibleConversion &operator=(impossibleConversion const & src);
				virtual ~impossibleConversion() throw();
				virtual const char *what() const throw();
		};
		Scalar();
		bool	validInput();
		unsigned char setFlags();
		int		convertInt();
		char	convertChar();
		float	convertFloat();
		double	convertDouble();
		int		setPrecision();
		std::string setInput(char const *input);
		float	epsilon(float a, float b);
		float	fless(float a, float b);
		double 	epsilon(double a, double b);
		double 	dless(double a, double b);
	public:
		Scalar(char const *input);
		Scalar(Scalar const & src);
		~Scalar();
		Scalar	&operator=(Scalar const & src);
		void	displayInt();
		void	displayChar();
		void	displayFloat();
		void	displayDouble();
		void	debug();
};

#endif
