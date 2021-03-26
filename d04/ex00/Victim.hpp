/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Victim.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:05:54 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:40:50 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim {
	private:
		std::string _name;
		Victim();
	public:
		Victim (std::string const & name);
		Victim (Victim const & src);
		virtual ~Victim ();
		Victim &operator=(Victim const &rhs);
		virtual void getPolymorphed() const;
		std::string const & getName() const;
};

std::ostream &operator<<(std::ostream &output, Victim const &rhs);

#endif
