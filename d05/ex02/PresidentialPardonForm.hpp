/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 22:26:42 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:47:32 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm 
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm();
		virtual	void	execute(Bureaucrat const & executor) const;
};

#endif
