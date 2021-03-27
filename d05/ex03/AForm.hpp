/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 19:00:03 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:56:42 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool		_signed;
		unsigned int const _signedGrade;
		unsigned int const _executeGrade;
		unsigned int const _maxGrade;
		unsigned int const _minGrade;
		std::string			_target;
		Form();
	protected:
		void	performChecks(Bureaucrat const & executor, Form const &Form) const;
	public:
		Form(std::string const & name, std::string const & target, unsigned int signedGrade, unsigned int executeGrade);
		Form(Form const & src);
		Form	&operator=(Form const & rhs);
		virtual ~Form();
		std::string	getName() const;
		bool		getSign() const;
		std::string getTarget() const;
		unsigned int			getSignedGrade() const;
		unsigned int			getExecuteGrade() const;
		unsigned int			getMaxGrade() const;
		unsigned int			getMinGrade() const;
		void					beSigned(Bureaucrat & bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
    	class GradeTooHighException : public std::exception
    	{
			private:
				std::string	_formName;
				std::string	_type;
				std::string	_error;
    		public:
    		    GradeTooHighException();
    		    GradeTooHighException(std::string name, std::string type);
    		    GradeTooHighException(const GradeTooHighException &src);
    		    GradeTooHighException &operator= (const GradeTooHighException &rhs);
    		    virtual ~GradeTooHighException(void) throw();
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
    		    GradeTooLowException(std::string name, std::string type);
    		    GradeTooLowException(const GradeTooLowException &src);
    		    GradeTooLowException  &operator= (const GradeTooLowException &rhs);
    		    virtual ~GradeTooLowException(void) throw();
    		    virtual const char    *what() const throw();

    	};
    	class NotSignedException: public std::exception
    	{
			private:
				std::string	_formName;
				std::string _error;
    		    NotSignedException();
    		public:
    		    NotSignedException(std::string name);
    		    NotSignedException(const NotSignedException &src);
    		    NotSignedException &operator= (const NotSignedException &rhs);
    		    virtual ~NotSignedException(void) throw();
    		    virtual const char    *what() const throw();

    	};
};

std::ostream	&operator<<(std::ostream &output, Form const &rhs);

# endif
