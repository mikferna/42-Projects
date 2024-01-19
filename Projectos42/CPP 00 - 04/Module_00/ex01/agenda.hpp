/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:08:56 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/19 12:51:28 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <iomanip>
#include <cstring>

class Contact
{
	private:
		std::string firstName, lastName, \
			nickname, phoneNumber, darkestSecret;
		int index;
	public:
		bool emptyContact();
		void create(int i);
		void getInfo();
		void printInfo();
};

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		void	add();
		void	search();
		bool	noContacts();
		bool	contactCheck(int i);
};

bool isEmpty(std::string s);
bool isNumber(std::string s);

#endif