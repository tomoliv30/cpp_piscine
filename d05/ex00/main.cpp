/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 14:02:34 by totartar      #+#    #+#                 */
/*   Updated: 2020/12/01 09:33:53 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
		std::cout << "Bureaucrat tom(\"Tom\", 140)" << std::endl;
		Bureaucrat 	tom("Tom", 140);
		std::cout << tom << std::endl;

		std::cout << "Bureaucrat olivier(\"Olivier\", 5)" << std::endl;
		Bureaucrat 	olivier("Olivier", 5);
		std::cout << olivier << std::endl;

		std::cout << "Bureaucrat sean(\"Sean\", 150)" << std::endl;
		Bureaucrat	sean("Sean", 150);
		std::cout << sean << std::endl;
		try
		{
			std::cout << "Bureaucrat paul(\"Paul\", 1098)" << std::endl;
			Bureaucrat	paul("Paul", 1098);
			std::cout << paul << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught std::exception, e.what() --> " << e.what() << std::endl;
		}

		try
		{
			std::cout << "Bureaucrat olivia(\"Olivia\", 0)" << std::endl;
			Bureaucrat	olivia("Olivia", 0);
			std::cout << olivia << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught std::exception, e.what() --> " << e.what() << std::endl;
		}

		try
		{
			std::cout << "tom.downgrade()" << std::endl;
			for (int i = 0; i < 20; i++) {
				tom.downgrade();
				std::cout << tom;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "caught std::exception, e.what() --> " << e.what() << std::endl;
		}
		try
		{
			std::cout << "olivier.upgrade()";
			for (int i = 0; i < 20; i++) {
				olivier.upgrade();
				std::cout << olivier;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "caught std::exception, e.what() --> " << e.what() << std::endl;
		}
	return 0;
}
