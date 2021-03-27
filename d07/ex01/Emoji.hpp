/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Emoji.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 17:04:48 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:33:42 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef EMOJI_HPP
# define EMOJI_HPP

class Emoji {

	private:
		std::string  _emoji;
	public:
		Emoji() ;
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
