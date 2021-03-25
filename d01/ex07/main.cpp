/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 17:46:33 by totartar      #+#    #+#                 */
/*   Updated: 2021/03/25 10:36:59 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h>

enum	e_error
{
	INTERRUPT
};

void	initArgs(int ac, 
		char **av, 
		std::string &toFind, 
		std::size_t &toFindLen,
		std::string &toReplace)
{

	if (ac != 4) {
		std::cerr << "expected 3 arguments, got " << ac - 1 << "." << std::endl;
		throw (INTERRUPT);
	}
	std::ifstream	file(av[1]);
	if (!file) {
		std::cerr << av[1] << ": invalid file." << std::endl;
		throw (INTERRUPT);
	}
	file.close();
	toFind = av[2];
	toReplace = av[3];
	toFindLen = toFind.length();
	if (!toFindLen) {
		std::cerr << "string to find is empty." << std::endl;
		throw (INTERRUPT);
	}
	else if (!toReplace.length()){
		std::cerr << "string to replace with is empty." << std::endl;
		throw (INTERRUPT);
	}
}

bool	safe_io(std::ifstream *oldFile, std::ofstream *newFile)
{
	if ((*oldFile).bad() || (*oldFile).fail()
			|| (*newFile).bad() || (*newFile).fail()) {
		return (false);
	}
	return (true);
}

void	ft_sed(char *file, 
		std::string const &toFind, 
		std::size_t toFindLen, 
		std::string const &toReplace)
{
	std::string	sampled = file;
	std::size_t	pos, len, sampledLen = 0;
	std::ifstream	oldFile(file);
	std::ofstream	newFile((sampled.substr(0, sampled.find_last_of(".")) 
				+ static_cast<std::string>(".replace")).c_str());

	oldFile.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
	newFile.exceptions(std::ofstream::failbit | std::ofstream::badbit | std::ifstream::eofbit);
	try
	{
		while (safe_io(&oldFile, &newFile) 
				&& getline(oldFile, sampled)) 
		{
			len = 0;
			pos = 0;
			sampledLen = sampled.length();
			while (safe_io(&oldFile, &newFile)
					&& len != std::string::npos && pos < sampledLen) 
			{
				len = sampled.find(toFind, pos);
				if (len != std::string::npos) {
					newFile << sampled.substr(pos, len - pos) << toReplace;
					pos = len + toFindLen;
				}
				else {
					sampledLen -= pos;
					newFile << sampled.substr(pos, sampledLen);
				}
			}
			newFile << std::endl;
		}
		oldFile.close();
		newFile.close();
	}
	catch (std::ios_base::failure &e)
	{
		if (!sampled.length())
			oldFile.clear();
		else
			throw(e);
	}
}

int	main(int ac, char **av)
{
	std::string		toFind, toReplace;
	std::size_t toFindLen = 0;
	try
	{
		initArgs(ac, av, toFind, toFindLen, toReplace);
		ft_sed(av[1], toFind, toFindLen, toReplace);
	}
	catch (e_error)
	{
		std::cerr << "exiting..." << std::endl;
		return EXIT_FAILURE;
	}
	catch (std::exception  &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "exiting..." << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
