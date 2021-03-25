/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 17:04:16 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/18 17:43:34 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap(void) {
	std::cout << "entering ponyOnTheHeap function scope...." << std::endl;
	std::cout << "creating heapPony..." << std::endl;
	Pony *heapPony = new Pony("heapPony", 5);
	heapPony->Bark();
	heapPony->Meow();
	std::cout << "deleting heapPony...." << std::endl;
	delete heapPony;
	std::cout << "exiting ponyOnTheHeap function scope...." << std::endl;
}

void	ponyOnTheStack(void) {
	std::cout << "entering ponyOnTheStack function scope...." << std::endl;
	std::cout << "creating stackPony..." << std::endl;
	Pony stackPony("stackPony", 1);
	stackPony.Bark();
	stackPony.Meow();
	std::cout << "exiting ponyOnTheStack function scope...." << std::endl;
}

int	main(void) {
	std::cout << "Calling ponyOnTheHeap..\n\n" << std::endl;
	ponyOnTheHeap();
	std::cout << "\n\nCalling ponyOnTheStack..\n\n" << std::endl;
	ponyOnTheStack();
	return 0;
}
