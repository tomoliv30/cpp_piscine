/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   NinjaTrap.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 22:23:22 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:03:57 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap {
	private:
		NinjaTrap();
	public:
		NinjaTrap(std::string const & name);
		NinjaTrap(NinjaTrap const & src);
		NinjaTrap & operator=(NinjaTrap const & rhs);
		virtual ~NinjaTrap();
		void 		ninjaShoebox(NinjaTrap &target);
		void 		ninjaShoebox(ClapTrap &target);
		void 		ninjaShoebox(FragTrap &target);
		void 		ninjaShoebox(ScavTrap &target);
};

#endif
