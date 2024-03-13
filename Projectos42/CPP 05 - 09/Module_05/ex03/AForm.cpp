/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:40:22 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/04 15:19:21 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(std::string const & name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src.getName()), _signed(src.getSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
}

AForm::~AForm()
{
}

AForm & AForm::operator=(AForm const & src)
{
	this->_signed = src.getSigned();
	return (*this);
}

std::string const & AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() <= _signGrade)
    {
        _signed = true;
    }
	else if (_signed)
	{
		std::cout << "Form is already signed" << std::endl;
	}
    else
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::showRequirements() const
{
	std::cout << "Form Name: " << _name << std::endl;
	std::cout << "Signed: " << (_signed ? "Yes" : "No") << std::endl;
	std::cout << "Sign Grade: " << _signGrade << std::endl;
	std::cout << "Execution Grade: " << _execGrade << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << "Form " << _name << " has been executed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << "Form Name: " << AForm.getName() << std::endl;
    out << "Signed: " << (AForm.getSigned() ? "Yes" : "No") << std::endl;
    out << "Sign Grade: " << AForm.getSignGrade() << std::endl;
    out << "Execution Grade: " << AForm.getExecGrade() << std::endl;
    return out;
}
