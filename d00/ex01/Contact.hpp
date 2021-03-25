/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: totartar <totartar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:53:12 by totartar      #+#    #+#                 */
/*   Updated: 2020/11/16 15:24:37 by totartar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

enum	e_info
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	LOGIN,
	POSTAL_ADDRESS,
	EMAIL_ADDRESS,
	PHONE_NUMBER,
	BIRTHDAY_DATE,
	FAVORITE_MEAL,
	UNDERWEAR_COLOR,
	DARKEST_SECRET
};

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _login;
		std::string _postalAddress;
		std::string _emailAddress;
		std::string _phoneNumber;
		std::string _birthdayDate;
		std::string _favoriteMeal;
		std::string _underwearColor;
		std::string _darkestSecret;
	public:
		Contact();
		Contact(std::string firstName, std::string lastName);
		Contact(Contact const & src);
		virtual ~Contact();
		Contact &operator=(Contact const & rhs);
		std::string	getInfo(int type) const;
		void	setAttribute(int type, std::string prompt);
};

#endif
