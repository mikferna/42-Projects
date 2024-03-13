/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:09:02 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/22 13:13:44 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "\nTEST 1\n";
		Form F("Test", 151, 42);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout <<  "\nTEST 2\n";
		Form F("Test", 42, -42);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout << "\nTEST 3\n";
		Form F("Test", 42, 42);
		std::cout << F;
		Bureaucrat B1("Pepe", 100);
		Bureaucrat B2("David", 24);
		F.beSigned(B2);
		F.beSigned(B1);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout << "\nTEST 4\n";
		Form F("Test", 84, 42);
		std::cout << F;
		Bureaucrat B1("Pepe", 100);
		F.beSigned(B1);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout << "\nTEST 5\n";
		Form F("Test", 84, 42);
		std::cout << F;
		Bureaucrat B1("Pepe", 100);
		//B1.signForm(F);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	return 0;
}