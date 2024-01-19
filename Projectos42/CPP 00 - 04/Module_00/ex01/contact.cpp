/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:51:07 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/19 12:39:57 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

void Contact::create(int i)
{
	do {
		std::cout << "Ingrese el nombre: ";
		getline(std::cin, firstName);
	} while (isEmpty(firstName));
	do {
		std::cout << "Ingrese el apellido: ";
		getline(std::cin, lastName);
	} while (isEmpty(lastName));
	do {
		std::cout << "Ingrese el apodo: ";
		getline(std::cin, nickname);
	} while (isEmpty(nickname));
	while (1)
	{
		std::cout << "Ingrese el numero de telefono: ";
		getline(std::cin, phoneNumber);
		if (!isNumber(phoneNumber) || isEmpty(phoneNumber))
			std::cout << "Numero de telefono invalido\n";
		else
			break ;
	}
	do {
		std::cout << "Ingrese el secreto mas oscuro: ";
		getline(std::cin, darkestSecret);
	} while (isEmpty(darkestSecret));
	index = i;
	std::cout << "Contacto creado con exito\n";
}

std::string resizeString(std::string s, int len) {
		s.resize(len);
	return s;
}

void Contact::getInfo() {
	if (!isEmpty(firstName)) {
		std::cout << std::setw(10) << index << "|";
		std::cout << std::setw(10) << (firstName.length() < 10 ? firstName : resizeString(firstName, 9)+'.') << "|";
		std::cout << std::setw(10) << (lastName.length() < 10 ? lastName : resizeString(lastName, 9)+'.') << "|";
		std::cout << std::setw(10) << (nickname.length() < 10 ? nickname : resizeString(nickname, 9)+'.') << "\n";
	}
}

void Contact::printInfo() {
	std::cout << "\nInformación de contacto:\n";
	std::cout << " firstName: " + firstName << std::endl;
	std::cout << " lastName: " + lastName << std::endl;
	std::cout << " nickname: " + nickname << std::endl;
	std::cout << " phoneNumber: " + phoneNumber << std::endl;
	std::cout << " darkestSecret: " + darkestSecret << std::endl;
	std::cout << "\n";
}

bool Contact::emptyContact()
{
	if (isEmpty(firstName))
		return true;
	return false;
}
