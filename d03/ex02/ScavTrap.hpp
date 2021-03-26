/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 18:53:22 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:01:38 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(ScavTrap const & src);
		ScavTrap(std::string const & name);
		ScavTrap &operator=(ScavTrap const & rhs);
		virtual ~ScavTrap();
		void		challengeNewcomer(std::string const &target);
};

#endif
