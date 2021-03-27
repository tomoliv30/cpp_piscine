/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 22:16:32 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 10:47:43 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm 
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);
		virtual ~RobotomyRequestForm();
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif
