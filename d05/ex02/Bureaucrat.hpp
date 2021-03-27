/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:59:10 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:18:12 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>

class	AForm;

class Bureaucrat {
	private:
		std::string 	const _name;
		unsigned int				_grade;
		unsigned int				_maxGrade;
		unsigned int				_minGrade;
		Bureaucrat();
	public:
		Bureaucrat(std::string const & name, unsigned int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat	&operator=(Bureaucrat const & src);
		~Bureaucrat();
		std::string const & getName() const;
		unsigned int			getGrade() const;
		unsigned int			getMinGrade() const;
		unsigned int			getMaxGrade() const;
		void					upgrade();
		void					downgrade();
		void					signForm(AForm & form);
		void					executeForm(AForm const & form);
    	class GradeTooLowException : public std::exception
    	{
    		public:
    		    GradeTooLowException();
    		    GradeTooLowException(GradeTooLowException const & src);
    		    virtual ~GradeTooLowException() throw();
    		    GradeTooLowException  &operator= (GradeTooLowException const & rhs);
    		    virtual const char    *what() const throw();
    	};

    	class GradeTooHighException : public std::exception
    	{
    		public:
    		    GradeTooHighException();
    		    GradeTooHighException(GradeTooHighException const & src);
    		    virtual ~GradeTooHighException() throw();
    		    GradeTooHighException &operator= (GradeTooHighException const & rhs);
    		    virtual const char    *what() const throw();
    	};
};

std::ostream	&operator<<(std::ostream &output, Bureaucrat const & rhs);

#endif
