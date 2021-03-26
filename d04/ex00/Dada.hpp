/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dada.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 08:52:01 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:36:50 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef DADA_HPP
# define DADA_HPP

# include "Victim.hpp"

class Dada : virtual public Victim {
	private:
		std::string _name;
		Dada();
	public:
		Dada (std::string const & name);
		Dada(Dada const & src);
		Dada &operator=(Dada const &rhs);
		virtual ~Dada();
		virtual void getPolymorphed() const;
};

std::ostream &operator<<(std::ostream &output, Dada const &rhs);

#endif
