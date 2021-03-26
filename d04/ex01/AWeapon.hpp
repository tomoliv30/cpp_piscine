/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AWeapon.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 18:11:22 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:42:18 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

enum e_attributes
{
	DAMAGE,
	AP_COST
};

class AWeapon {
	private:
		std::string 	const _name;
		unsigned int	_damage;
		unsigned int	_apcost;
		AWeapon();
	protected:
		void	setAttributes(unsigned int damage, unsigned int apcost);
	public:
		AWeapon(std::string const & name, unsigned int apcost, unsigned int damage);
		AWeapon(AWeapon const & src);
		AWeapon &operator=(AWeapon const &rhs);
		virtual ~AWeapon();
		std::string  const & getName() const;
		unsigned int 	getAttribute(int type) const;
		virtual void	attack() const = 0;
};

#endif
