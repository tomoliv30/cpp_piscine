/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 13:30:52 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:45:33 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int				_fixedPointValue;
		static const int _binaryPoint= 8;
	public:
		Fixed ();
		Fixed(Fixed const &toCopy);
		Fixed(int const toConvert);
		Fixed(float const toConvert);
		virtual ~Fixed ();
		Fixed& operator=(Fixed const &rhs);
		int	getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream&	operator<<(std::ostream &output, Fixed const &toOutput);

#endif
