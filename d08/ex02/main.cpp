/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 10:22:41 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/09 18:18:30 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <sstream>

int main()
{
	{
		MutantStack<int> mstack;
		std::cout << "push 5 and 17" << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack.top() --> "<< mstack.top() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		std::cout << "mstack.top() --> "<< mstack.top() << std::endl;
		std::cout << "mstack.size() --> "<< mstack.size() << std::endl;
		std::cout << "mstack.push 3 5 737 0"<< std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "print stack" << std::endl;
		while (it != ite)
		{
			std::cout << *it << " " << std::endl;
			++it;
		}
		std::cout << "print until it == mstack.begin()" << std::endl;
		it--; //cause it == end()
		while (it != mstack.begin())
		{
			std::cout << *it << std::endl;
			it--;
		}
		std::stack<int> s(mstack);
		std::cout << "pop everything" << std::endl;
		while (mstack.size())
		{
			mstack.pop();
			s.pop();
		}
		std::cout << "mstack.empty() --> " << mstack.empty() <<
		std::endl << "s.empty() --> " << s.empty() << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << "push " << i << std::endl;
			mstack.push(i);
			s.push(i);
		}
		std::cout << "mstack.top() --> " << mstack.top() <<
		std::endl << "s.top() --> " << s.top() << std::endl;

		MutantStack<int>::reverse_iterator rbegin = mstack.rbegin();
		MutantStack<int>::reverse_iterator rend = mstack.rend();

		std::cout << "print while rbegin != rend" << std::endl;
		while (rbegin != rend)
		{
			std::cout << *rbegin << std::endl;
			rbegin++;
		}
	}
	{
		MutantStack<std::string> mstack;
		std::cout << "push yes and no" << std::endl;
		mstack.push("yes");
		mstack.push("no");
		std::cout << "mstack.top() --> "<< mstack.top() << std::endl;
		std::cout << "mstack.pop()" << std::endl;
		mstack.pop();
		std::cout << "mstack.top() --> "<< mstack.top() << std::endl;
		std::cout << "mstack.size() --> "<< mstack.size() << std::endl;
		std::cout << "mstack.push str1 str2 str3"<< std::endl;
		mstack.push("str1");
		mstack.push("str2");
		mstack.push("str3");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "print stack" << std::endl;
		while (it != ite)
		{
			std::cout << *it << " " << std::endl;
			++it;
		}
		std::cout << "print until it == mstack.begin()" << std::endl;
		it--; //cause it == end()
		while (it != mstack.begin())
		{
			std::cout << *it << std::endl;
			it--;
		}
		std::stack<std::string> s(mstack);
		std::cout << "pop everything" << std::endl;
		while (mstack.size())
		{
			mstack.pop();
			s.pop();
		}
		std::cout << "mstack.empty() --> " << mstack.empty() <<
		std::endl << "s.empty() --> " << s.empty() << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::stringstream conv;
			conv << i;
			std::string temp = "str";
			temp += conv.str();
			std::cout << "push " << temp << std::endl;
			mstack.push(temp);
			s.push(temp);
		}
		std::cout << "mstack.top() --> " << mstack.top() <<
		std::endl << "s.top() --> " << s.top() << std::endl;

		MutantStack<std::string>::reverse_iterator rbegin = mstack.rbegin();
		MutantStack<std::string>::reverse_iterator rend = mstack.rend();

		std::cout << "print while rbegin != rend" << std::endl;
		while (rbegin != rend)
		{
			std::cout << *rbegin << std::endl;
			rbegin++;
		}
	}
	return 0;
}
