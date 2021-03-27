/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 19:00:03 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:14:57 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool		_signed;
		unsigned int const _signedGrade;
		unsigned int const _executeGrade;
		unsigned int const _maxGrade;
		unsigned int const _minGrade;
		std::string			_target;
		AForm();
	protected:
		void	performChecks(Bureaucrat const & executor, AForm const &AForm) const;
	public:
		AForm(std::string const & name, std::string const & target, unsigned int signedGrade, unsigned int executeGrade);
		AForm(AForm const & src);
		AForm	&operator=(AForm const & rhs);
		virtual ~AForm();
		std::string	const & getName() const;
		bool		getSign() const;
		std::string const & getTarget() const;
		unsigned int			getSignedGrade() const;
		unsigned int			getExecuteGrade() const;
		unsigned int			getMaxGrade() const;
		unsigned int			getMinGrade() const;
		void					beSigned(Bureaucrat const & bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
    	class GradeTooHighException : public std::exception
    	{
			private:
				std::string	_formName;
				std::string	_type;
				std::string	_error;
    		public:
    		    GradeTooHighException();
    		    GradeTooHighException(std::string const & name, std::string const & type);
    		    GradeTooHighException(const GradeTooHighException &src);
    		    GradeTooHighException &operator= (const GradeTooHighException &rhs);
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
    	class NotSignedException: public std::exception
    	{
			private:
				std::string	_formName;
				std::string _error;
    		    NotSignedException();
    		public:
    		    NotSignedException(std::string const & name);
    		    NotSignedException(NotSignedException const & src);
    		    NotSignedException &operator= (NotSignedException const & rhs);
    		    virtual ~NotSignedException() throw();
    		    virtual const char    *what() const throw();

    	};
};

std::ostream	&operator<<(std::ostream &output, AForm const &rhs);

# endif
