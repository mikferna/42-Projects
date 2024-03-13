/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:25:24 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/04 15:27:43 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern& obj )
{
	(void)obj;
}

Intern::~Intern()
{
}

Intern& Intern::operator=( const Intern& obj )
{
	(void)obj;
	return *this;
}

AForm* Intern::makeForm( std::string formName, std::string target ) {
	int i;
	AForm* selectedForm;
	std::string constructors[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (i = 0; i < 3; i++) {
		if (constructors[i] == formName)
			break;
	}
	switch (i) {
		case 0:
			selectedForm = new PresidentialPardonForm(target);
			break;
		case 1:
			selectedForm = new RobotomyRequestForm(target);
			break;
		case 2:
			selectedForm = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "Can't create that form\n";
			throw NonExistanceForm();
	}
	std::cout << "Intern creates " << formName << "\n";
	return selectedForm;
}
