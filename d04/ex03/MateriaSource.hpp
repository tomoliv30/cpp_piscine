/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:18:44 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:52:10 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource {
	private:
		std::string	_name;
		AMateria	*_inventory[4];
		unsigned int			_n_materia;
	public:
		MateriaSource();
		MateriaSource(std::string const & name);
		MateriaSource(MateriaSource const & src);
		~MateriaSource();
        MateriaSource       &operator= (MateriaSource const & rhs);
        virtual void        learnMateria(AMateria *m);
        virtual AMateria    *createMateria(std::string const & type);
		void				displayInventory();
};

#endif
