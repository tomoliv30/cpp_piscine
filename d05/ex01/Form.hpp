/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:56:55 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:09:01 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool		_signed;
		unsigned int const _signedGrade;
		unsigned int const _executeGrade;
		unsigned int const _maxGrade;
		unsigned int const _minGrade;
	public:
		Form();
		Form(std::string const & name, unsigned int const signedGrade, unsigned int const executeGrade);
		Form(Form const & src);
		Form	&operator=(Form const & rhs);
		~Form();
		std::string	getName() const;
		bool		getSign() const;
		unsigned int			getSignedGrade() const;
		unsigned int			getExecuteGrade() const;
		unsigned int			getMaxGrade() const;
		unsigned int			getMinGrade() const;
		void					beSigned(Bureaucrat const & bureaucrat);
    	class GradeTooHighException : public std::exception
    	{
			private:
				std::string	_formName;
				std::string	_type;
				std::string	_error;
    		public:
    		    GradeTooHighException();
    		    GradeTooHighException(std::string const & name, std::string const & type);
    		    GradeTooHighException(GradeTooHighException const & src);
    		    GradeTooHighException &operator= (GradeTooHighException const & rhs);
    		    virtual ~GradeTooHighException() throw();
    		    virtual const char    *what() const throw();
    	};
    	class GradeTooLowException : public std::exception
    	{
			private:
				std::string	_formName;
				std::string	_type;
				std::string	_error;
    		public:
    		    GradeTooLowException();
    		    GradeTooLowException(std::string const & name, std::string const & type);
    		    GradeTooLowException(GradeTooLowException const & src);
    		    GradeTooLowException  &operator= (GradeTooLowException const & rhs);
    		    virtual ~GradeTooLowException() throw();
    		    virtual const char    *what() const throw();
    	};
};

std::ostream	&operator<<(std::ostream &output, Form const &rhs);

# endif
