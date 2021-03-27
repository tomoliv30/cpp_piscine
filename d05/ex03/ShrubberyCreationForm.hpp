/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 19:44:07 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 00:45:23 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public Form 
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const & rhs);
		virtual ~ShrubberyCreationForm();
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif

