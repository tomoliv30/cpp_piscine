/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Human.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 09:00:12 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/19 10:34:15 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

class Human {
	private:
		std::string _name;
		int			_age;
		const Brain 		_brain;
	public:
		Human();
		Human(Human const &src);
		virtual ~Human();
		Human &operator=(Human const &rhs);
		std::string	identify();
		const Brain	&getBrain() const;
};
