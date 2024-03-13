/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:09:02 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/28 13:27:18 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		std::cout << "\nTEST 1:\n";
		RobotomyRequestForm R("Igor");
		R.showRequirements();
		Bureaucrat B("Susana", 42);
		R.beSigned(B);
		B.executeForm(R);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout << "\nTEST 2:\n";
		Bureaucrat B("Jesus", 100);
		std::cout << B;
		PresidentialPardonForm P("me");
		P.showRequirements();
		P.beSigned(B);
		B.executeForm(P);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout << "\nTEST 3:\n";
		ShrubberyCreationForm S("home");
		PresidentialPardonForm P("me");
		RobotomyRequestForm R("me");
		S.showRequirements();
		P.showRequirements();
		R.showRequirements();
		Bureaucrat B1("Susana", 42);
		Bureaucrat B2("Sofia", 140);
		std::cout << B2;
		S.beSigned(B2);
		S.showRequirements();
		std::cout << B1;
		B1.executeForm(S);
		B2.executeForm(S);
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	try {
		std::cout << "\nTEST 4:\n";
		Bureaucrat B("Not Signed", 1);
		RobotomyRequestForm R("me");
		R.showRequirements();
		B.executeForm(R);

	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	return 0;
}