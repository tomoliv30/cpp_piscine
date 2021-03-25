/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 13:18:40 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:44:57 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int				_fixedPointValue;
		static int const _binaryPoint = 8;
	public:
		Fixed();
		Fixed(Fixed const &to_copy);
		virtual ~Fixed();
		Fixed& operator=(Fixed const &rhs);
		int	getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
