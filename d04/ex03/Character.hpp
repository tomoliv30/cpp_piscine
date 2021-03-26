/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:19:28 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:49:51 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : virtual public ICharacter {
	private:
		std::string 				_name;
		unsigned int				_n_materia;
        AMateria                   *_inventory[4];
		void				cloneInventory(Character const & rhs);
	public:
        Character(void);
        Character(std::string const & name);
        Character(Character const & src);
		virtual ~Character();
        Character                   &operator= (Character const & rhs);
		const std::string 	&getName() const;
		unsigned int		getNMateria() const;
		void 	unequip(int idx);
		void	equip(AMateria* m);
		void 	use(int idx, ICharacter& target);
		void	displayInventory();
};

#endif
