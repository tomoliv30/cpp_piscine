/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 00:10:14 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 11:13:19 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	private:
		std::string _validInput[3];
		Form *_newPresidentialPardonForm(std::string target);
		Form *_newRobotomyRequestForm(std::string target);
		Form *_newShrubberyCreationForm(std::string target);
		Form *(Intern::*_forms[4])(std::string);
		int	_parseInput(std::string formName);
	public:
    	class FormNotFoundException: public std::exception
    	{
    		public:
    		    FormNotFoundException(void);
    		    FormNotFoundException(const FormNotFoundException &src);
    		    virtual ~FormNotFoundException(void) throw();
    		    FormNotFoundException&operator= (const FormNotFoundException &rhs);
    		    virtual const char    *what() const throw();
    	};
		Intern();
		Intern(Intern const &);
		~Intern();
		Intern	&operator=(Intern const &);
		Form *makeForm(std::string formName, std::string target);
};

#endif
