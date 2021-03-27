/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 14:27:56 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:43:40 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAN_HPP
# define SCAN_HPP

# include <iostream>
# include <vector>

enum e_flags
{
	S_SPAN = 1,
	L_SPAN
};

class Span
{
	private:
		std::vector<int>	_items;
		unsigned int		_size;
		unsigned int		_capacity;
		unsigned long 		_shortestSpan;
		unsigned long 		_longestSpan;
		unsigned char		_flags;
		typedef std::vector<int>::iterator InputIterator;
		class	CapacityReached : public std::exception {
			public:
				CapacityReached();
				CapacityReached(CapacityReached const & src);
				virtual ~CapacityReached() throw ();
     			CapacityReached &operator= (CapacityReached const & rhs);
     	 		virtual const char    *what() const throw();
		};
		class	NoSpan : public std::exception {
			public:
				NoSpan();
				NoSpan(NoSpan const & src);
				virtual ~NoSpan() throw();
     			NoSpan &operator= (NoSpan const & rhs);
     	 		virtual const char    *what() const throw();
		};
		Span();
	public:
		Span(unsigned int N);
		Span(Span const & src);
     	Span &operator= (Span const & rhs);
		virtual ~Span();
		void	addNumber(int newNumber);
		void	addNumber(InputIterator first, InputIterator last);
		unsigned long 	shortestSpan();
		unsigned long 	longestSpan();
		void	printItems(std::string const & name) const;
};

#endif
