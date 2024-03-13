/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:41:17 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/04 15:39:07 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& obj ) : AForm("RobotomyRequestForm", 72, 45), _target(obj.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& obj )
{
	this->_target = obj.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << "[Drilling noises]\n";
	srand((unsigned) time(NULL));
	int random = rand() % 2;
	if (random)
		std::cout << this->_target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed\n";
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << a->getName() << " form with grade " << a->getSignGrade() << " to sign and " << a->getExecGrade() << " to execute";
	return (o);
}
