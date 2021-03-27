/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 11:53:07 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/06 18:31:45 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Emoji.hpp"

int	main()
{
	int a = 2;
	int b = 3;

	std::cout << "before swap a = " << a << ", b = " << b << std::endl;
	::swap( a, b);
	std::cout << "after swap a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "before swap c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after swap c = " << c << ", d = " << d << std::endl;
	std::cout<< "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::string *cptr = &c;
	std::string *dptr = &d;

	std::cout << "std::string *cptr = &c, std::string *dptr = &d" << std::endl;

	std::cout << "before swap cptr = " << cptr << ", dptr = " << dptr << std::endl;
	std::cout << "before swap c = " << c << ", d = " << d << std::endl;
	::swap(cptr, dptr);
	std::cout << "after swap cptr = " << cptr << ", dptr = " << dptr << std::endl;
	std::cout << "after swap c = " << c << ", d = " << d << std::endl;
	std::cout<< "min( cptr, dptr ) = " << ::min( cptr, dptr ) << std::endl;
	std::cout << "max( cptr, dptr ) = " << ::max( cptr, dptr ) << std::endl;


	std::cout << "swap(*cptr, *dptr)" << std::endl;
	std::cout << "before swap c = " << c << ", d = " << d << std::endl;
	std::cout << "before swap cptr = " << cptr << ", dptr = " << dptr << std::endl;
	::swap(*cptr, *dptr);
	std::cout << "after swap c = " << c << ", d = " << d << std::endl;
	std::cout << "after swap cptr = " << cptr << ", dptr = " << dptr << std::endl;

	Emoji a1(":)");
	Emoji b1(":(");
	
	std::cout << "Emoji a1(:)) Emoji b(:()" << std::endl;
	std::cout << "before swap a1 = " << a1 << ", b1 = " << b1 << std::endl;
	::swap( a1, b1);
	std::cout << "after swap a1 = " << a1 << ", b1 = " << b1 << std::endl;
	std::cout << "min( a1, b1 ) = " << ::min( a1, b1 ) << std::endl;
	std::cout << "max( a1, b1 ) = " << ::max( a1, b1 ) << std::endl;
	
	std::cout << "min (a1.getEmoji(), b1.getEmoji()) = "	<< ::min(a1.getEmoji(), b1.getEmoji()) << std::endl;
	std::cout << "max (a1.getEmoji(), b1.getEmoji()) = "	<< ::max(a1.getEmoji(), b1.getEmoji()) << std::endl;
	return (0);
}
