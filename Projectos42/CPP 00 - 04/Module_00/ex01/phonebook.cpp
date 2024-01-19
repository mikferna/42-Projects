/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:51:10 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/19 13:40:44 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

void PhoneBook::add()
{
	int i = 0;

	while (i < 7)
	{
		if (contacts[i].emptyContact())
			break;
		i++;
	}
	contacts[i].create(i);
}

void PhoneBook::search()
{
	std::cout << "\n     index| firstName|  lastName|  nickname\n\n";
	for (int i = 0; i < 8; i++)
		contacts[i].getInfo();
	std::cout << "\n";
}

bool PhoneBook::noContacts()
{
	if (contacts[0].emptyContact())
		return true;
	return false;
}

bool PhoneBook::contactCheck(int i)
{
	if (contacts[i].emptyContact())
	{
		std::cout << "\nNo existe ese contacto\n";
		return true;
	}
	else
		contacts[i].printInfo();
	return false;
}
