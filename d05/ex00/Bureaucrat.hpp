/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:59:10 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:12:22 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		std::string 		const 	_name;
		unsigned int				_grade;
		unsigned int				_maxGrade;
		unsigned int				_minGrade;
	public:
		Bureaucrat();
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
