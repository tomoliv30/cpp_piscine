/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dodo.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:05:45 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:37:33 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DODO_HPP
# define DODO_HPP

# include "Victim.hpp"

class Dodo : virtual public Victim {
	private:
		std::string _name;
		Dodo();
	public:
		Dodo (std::string const & name);
		Dodo(Dodo const & src);
		Dodo &operator=(Dodo const & rhs);
		virtual ~Dodo();
		virtual void getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &output, Dodo const &rhs);

#endif
