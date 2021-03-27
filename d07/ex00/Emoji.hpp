/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Emoji.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 17:04:48 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:30:36 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMOJI_HPP
# define EMOJI_HPP

#include <iostream>

class Emoji {

	private:
		std::string  _emoji;
		Emoji() ;
	public:
		Emoji(std::string const & emoji) ;
		Emoji(Emoji const & src) ;
		Emoji &operator=(Emoji const & rhs);
		virtual ~Emoji();
		bool operator>(Emoji const & rhs);
		bool operator<(Emoji const & rhs);
		std::string const & getEmoji() const;
};

std::ostream &operator<<(std::ostream & out, Emoji const & src);

#endif
