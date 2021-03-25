/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 08:59:43 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:14:27 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _address;
	public:
		Brain();
		Brain(Brain const &src);
		virtual ~Brain();
		Brain &operator=(Brain const &rhs);
		std::string	identify() const;
};

#endif
