/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 19:44:07 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 11:18:26 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm 
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const & rhs);
		virtual ~ShrubberyCreationForm();
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif

