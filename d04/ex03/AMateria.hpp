/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 09:19:24 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/26 11:48:08 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
	private:
		unsigned int _xp;
		static const unsigned int _maxXp = 100;
		std::string const  _type;
		std::string _name;
		AMateria();
		void	updateXP();
	public:
		AMateria(std::string const & type);
		AMateria(std::string const & type, std::string const & name);
		AMateria(AMateria const & src);
		AMateria	&operator=(AMateria const & rhs);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
		void	displayStats();
};

#endif
