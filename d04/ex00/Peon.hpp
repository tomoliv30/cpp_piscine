/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Peon.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:05:45 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:37:54 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : virtual public Victim {
	private:
		std::string _name;
		Peon();
	public:
		Peon (std::string const & name);
		Peon(Peon const & src);
		Peon &operator=(Peon const &rhs);
		virtual ~Peon();
		virtual void getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &output, Peon const &rhs);

#endif
