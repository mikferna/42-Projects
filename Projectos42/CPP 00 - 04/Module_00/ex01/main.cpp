/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:08:33 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/19 13:44:20 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

bool isEmpty(std::string s)
{
	if (s.empty())
		return true;
	for (int i = 0; i < (int)s.length(); i++)
		if (std::isspace(s[i]) == 0)
			return false;
	return true;
}

bool isNumber(std::string s)
{
	for (int i = 0; i < (int)s.length(); i++)
		if (std::isdigit(s[i]) == 0)
			return false;
	return true;
}

bool strcmp(std::string s1, std::string s2)
{
	if (s1.length() != s2.length())
		return (false);
	for (size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return (false);
	}
	return (true);
}

void printmenu()
{
	std::cout << "\nIngrese uno de los siguientes comandos:\n";
	std::cout << "ADD: Add contact" << std::endl;
	std::cout << "SEARCH: Search contact" << std::endl;
	std::cout << "EXIT: Exit" << std::endl;
}

int main()
{
	PhoneBook	phonebook;
	std::string command;

	printmenu();
	while (getline(std::cin, command))
	{
		if (strcmp(command, "ADD"))
			phonebook.add();
		else if (strcmp(command, "SEARCH"))
		{
			if (phonebook.noContacts())
			{
				std::cout << "No hay contactos en la agenda\n";
				printmenu();
				continue;
			}
			phonebook.search();
			std::cout << "Ingrese el indice del contacto que desea ver: ";
			getline(std::cin, command);
			if (isEmpty(command) || !isNumber(command))
				std::cout << "Indice invalido" << std::endl;
			else
			{
				if (phonebook.contactCheck(stoi(command)))
					continue;
			}
		}
		else if (strcmp(command, "EXIT"))
			break;
		else
			std::cout << "Comando no valido" << std::endl;
		printmenu();
	}
	return (0);
}
