/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:25:17 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/04 14:09:30 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class Intern {
	public:
		Intern();
		Intern( const Intern& obj );
		~Intern();

		Intern& operator=( const Intern& obj );

		AForm *makeForm( std::string formName, std::string target );

		class NonExistanceForm : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Form not found");
				}
		};
};

#endif
