/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:31:22 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/27 15:22:30 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>
#define ALNUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
#include <algorithm>

struct	Data {
	std::string s1; 
	int n; 
	std::string s2; 
};

std::string	generateRandomStr() {
	std::string	s;
	s.resize(8);
	for (size_t i = 0; i < s.size(); ++i) {
		s[i] = ALNUM[rand() % 62];
	}
	return s;
}

void	*serialize()
{
	size_t	const	string_size = sizeof(std::string);
	size_t	const	int_size = sizeof(int);
	size_t	const	padding_size = 4;
	unsigned char 	*serialized = (unsigned char *)malloc(sizeof(Data));
	std::string 	*string_ptr;
	int				*int_ptr;

	string_ptr = reinterpret_cast<std::string *>(serialized);
	*string_ptr = generateRandomStr();
	std::cout<<"raw s1: "<< *string_ptr <<std::endl;

	int_ptr = reinterpret_cast<int *>(serialized + string_size);
	*int_ptr = rand() % 100;
	std::cout<<"raw n: " << *int_ptr << std::endl;

	string_ptr = reinterpret_cast<std::string *>(serialized + string_size + int_size + padding_size); 
	*string_ptr = generateRandomStr();
	std::cout<<"raw s2: "<< *string_ptr <<std::endl;

	return serialized;
}

Data	* deserialize(void *raw)
{
	return reinterpret_cast<Data *>(raw);
}

void	printStruct(Data *deserialized)
{
	std::cout << "(Data)" << std::endl;
	std::cout << "\t-->s1: " << static_cast<std::string>(deserialized->s1) << std::endl;
	std::cout << "\t-->n: " << deserialized->n << std::endl;
	std::cout << "\t-->s2: " << deserialized->s2 << std::endl;
}

int	main()
{
	void	*serialized;
	srand(time(NULL));

	try
	{
		for (unsigned int i = 0; i < 10; i++) {
			serialized = serialize();
			printStruct(deserialize(serialized));
			std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
