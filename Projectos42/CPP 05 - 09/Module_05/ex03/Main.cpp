/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:09:02 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/04 15:09:38 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
	try {
		std::cout << "\nTEST 1:\n";
		Intern I;
		AForm* form;
		form = I.makeForm("shrubbery creation", "Willy");
		form->showRequirements();
		delete form;
		form = I.makeForm("presidential pardon", "Billy");
		form->showRequirements();
		delete form;
		form = I.makeForm("robotomy request", "Bender");
		form->showRequirements();
		delete form;
		form = I.makeForm("other stuff", "Other");
		form->showRequirements();
		delete form;

	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	return 0;
}