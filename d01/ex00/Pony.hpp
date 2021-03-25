/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pony.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:58:57 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:09:51 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony {
	private:
		std::string _name;
		int 		_legs;
		Pony();
	public:
		Pony(std::string const &newName, int newLegs);
		Pony(Pony const & src);
		Pony &operator=(Pony const & rhs);
		virtual ~Pony();
		std::string getName() const;
		int			getLegs() const;
		void	Bark();
		void	Meow();
};

#endif
