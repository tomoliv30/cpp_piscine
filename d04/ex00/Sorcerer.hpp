/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sorcerer.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:05:38 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:39:55 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "Victim.hpp"

class Sorcerer {
	private:
		std::string _name;
		std::string _title;
		Sorcerer();
	public:
		Sorcerer (std::string const & name, std::string const & title);
		Sorcerer(Sorcerer const & src);
		virtual ~Sorcerer();
		Sorcerer &operator=(Sorcerer const & rhs);
		std::string const & getName() const;
		std::string const & getTitle() const;
		void	polymorph(Victim const &victim) const;
};

std::ostream &operator<<(std::ostream &output, Sorcerer const &rhs);

#endif
