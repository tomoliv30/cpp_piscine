/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 17:59:51 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:12:54 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

enum	e_attribute 
{
	NAME,
	TYPE
};

class Zombie {

	private:
		std::string _name;
		std::string _type;
	public:
		Zombie();
		Zombie(std::string const &name, std::string const &type);
		Zombie(Zombie const &src);
		Zombie &operator=(Zombie const & rhs);
		virtual ~Zombie();
		void	setAttribute(e_attribute attribute, std::string const &value);
		std::string	getAttribute(e_attribute attribute) const;
		void	announce();
};

#endif
