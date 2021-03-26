/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 17:27:35 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:06:59 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap(std::string const & name);
		FragTrap &operator=(FragTrap const & rhs);
		virtual ~FragTrap();
		void				rangedAttack(std::string const & target);
		void				meleeAttack(std::string const & target);
		void				vaulthunter_dot_exe(std::string const & target);
};

#endif
