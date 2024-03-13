/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:09:29 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/29 11:56:43 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("default") , _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

std::string const & Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::signForm(AForm& form)
{
	if (form.getSigned())
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because it is already signed" << std::endl;
	}
	else if (form.getSignGrade() < this->_grade)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	}
	else
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (!form.getSigned())
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because it is not signed" << std::endl;
	}
	else if (form.getExecGrade() < this->_grade)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because his grade is too low" << std::endl;
	}
	else
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
