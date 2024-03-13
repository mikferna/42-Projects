/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:34:23 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/27 12:07:30 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(std::string const & name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
}

Form::~Form()
{
}

Form & Form::operator=(Form const & src)
{
	if (this != &src)
	{
		_signed = src._signed;
	}
	return (*this);
}

std::string const & Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
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
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form Name: " << form.getName() << std::endl;
    out << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
    out << "Sign Grade: " << form.getSignGrade() << std::endl;
    out << "Execution Grade: " << form.getExecGrade() << std::endl;
    return out;
}
