/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutanstack.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 10:21:59 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/09 18:01:47 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const & src) : std::stack<T>(src) {}
		MutantStack &operator=(MutantStack const & rhs) {
			std::stack<T>::operator=(rhs);
			return *this;
		}
		virtual ~MutantStack() {}
		iterator begin() {
			return this->c.begin();
		}
		reverse_iterator rbegin() {
			return this->c.rbegin();
		}
		iterator end() {
			return this->c.end();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}
};

#endif
