/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:05:21 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/27 08:58:38 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Dodo.hpp"
#include "Dada.hpp"

int main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	Dodo tom("Tom");
	Dada olivier("Olivier");
	std::cout << tom << olivier;

	robert.polymorph(tom);
	robert.polymorph(olivier);
	return (0);
}
