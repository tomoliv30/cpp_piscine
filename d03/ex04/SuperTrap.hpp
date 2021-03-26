/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SuperTrap.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:58:52 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:12:13 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap:  virtual public FragTrap, virtual public NinjaTrap {
	private:
		SuperTrap();
	public:
		SuperTrap(std::string const & name);
		SuperTrap(SuperTrap const & src);
		virtual ~SuperTrap();
		SuperTrap & operator=(SuperTrap const & rhs);
		void				rangedAttack(std::string const & target);
		void				meleeAttack(std::string const & target);
};

#endif
