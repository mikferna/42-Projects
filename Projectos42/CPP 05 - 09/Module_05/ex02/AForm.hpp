/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:40:30 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/27 15:53:57 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAForm_HPP
#define AAForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
	public:
		AForm();
		AForm(std::string const & name, int signGrade, int execGrade);
		AForm(AForm const & src);
		~AForm();
		AForm & operator=(AForm const & src);
		std::string const & getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void showRequirements() const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade is too low");
				}
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Form not signed";
				}
		};
};

std::ostream& operator<<( std::ostream& o, const AForm& b );

#endif