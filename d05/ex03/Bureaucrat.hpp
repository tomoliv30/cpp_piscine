/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 12:59:10 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 11:14:06 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>

class	Form;

class Bureaucrat {
	private:
		std::string 			const _name;
		unsigned int				_grade;
		unsigned int				_maxGrade;
		unsigned int				_minGrade;
		Bureaucrat();
	public:
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat	&operator=(Bureaucrat const & src);
		~Bureaucrat();
		std::string const getName() const;
		unsigned int			getGrade() const;
		unsigned int			getMinGrade() const;
		unsigned int			getMaxGrade() const;
		void					upgrade();
		void					downgrade();
		void					signForm(Form & form);
		void					executeForm(Form const & form);
    	class GradeTooLowException : public std::exception
    	{
    		public:
    		    GradeTooLowException(void);
    		    GradeTooLowException(const GradeTooLowException &src);
    		    virtual ~GradeTooLowException(void) throw();
    		    GradeTooLowException  &operator= (const GradeTooLowException &rhs);
    		    virtual const char    *what() const throw();
    	};

    	class GradeTooHighException : public std::exception
    	{
    		public:
    		    GradeTooHighException(void);
    		    GradeTooHighException(const GradeTooHighException &src);
    		    virtual ~GradeTooHighException(void) throw();
    		    GradeTooHighException &operator= (const GradeTooHighException &rhs);
    		    virtual const char    *what() const throw();
    	};
};

std::ostream	&operator<<(std::ostream &output, Bureaucrat const & rhs);

#endif
