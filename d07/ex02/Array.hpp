/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 12:11:30 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:34:52 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class	Array
{
	private:
		T	*_array;
		unsigned int _size;
	public:

		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n) : _size(n)
		{
			if (!_size)
			{
				_array = NULL;
				return ;
			}
			try
			{
			 	_array = new T[_size]();
			}
			catch (std::exception & e)
			{
				std::cout << "error: " << e.what() << std::endl;
				_size = 0;
				_array = NULL;
				throw (e);
			}
		}
		Array(Array const & src) : _array(NULL), _size(0) { *this = src; }
		Array<T> &operator=(Array<T> const & src)
		{
			try
			{
				if (_array)
					delete[] _array;
				this->_size = src._size;
				if (!_size)
				{
					_array = NULL;
					return *this;
				}
			 	_array = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src[i];
			}
			catch (std::exception & e)
			{
				std::cout << "error: " << e.what() << std::endl;
				_size = 0;
				_array = NULL;
				throw (e);
			}
			return *this;
		}
		virtual T	&operator[](unsigned int index) const
		{
			if (index >= _size)
				throw (Array<T>::BadAccessException());
			return (this->_array[index]);
		}
		unsigned int	size() const { return this->_size; }
		~Array()
		{
			if (_size)
				delete[] _array;
		}
		class	BadAccessException : public std::exception
		{
    		public:
				BadAccessException() {}
				BadAccessException(BadAccessException const & src) { *this = src; }
				BadAccessException &operator= (BadAccessException const &) { return *this; }
				virtual ~BadAccessException() throw() {}
				virtual const char    *what() const throw() { return "index out of bound"; }

		};
		void	printArray(std::string name) 
		{
			if (!_array)
				return ;
			std::cout << name << ":";
			for (unsigned int i = 0;  i < _size ; i++) 
			{
				std::cout << _array[i] <<" ";
			}
			std::cout << std::endl;
		}
};

#endif
