/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:41:05 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/04 15:36:18 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& obj ) : AForm("ShrubberyCreationForm", 145, 137), _target(obj.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& obj )
{
	this->_target = obj.getTarget();
	return (*this);
}

#include <iostream>

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::ofstream file;
	file.open(_target + "_shrubbery");
	file << " ⢀⣀⡤⠤⠤⢤⣀⡀⠀⠀⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠉⠓⢦⣄⡀⠀⠉⠙⠲⢼⣧⡉⠙⠲⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠈⠙⠳⣤⡀⠀⢀⠈⠙⠲⣄⣄⠙⢦⣴⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠳⣌⡓⢤⡀⠈⠉⢣⠀⠻⠈⢷⠀⠀⢀⣀⣠⣤⣤⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⣠⣤⡤⠦⠤⠤⠤⠤⠤⠤⢤⣼⡿⣆⠙⢦⠀⠀⢧⠹⡄⠈⡷⠛⢉⣀⣀⡀⠀⠐⠻⠶⠤⢤⣄⡀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠉⠙⠛⠛⠓⠲⠶⠦⢤⣄⡀⠈⢡⡈⠑⢦⡱⡄⠈⣇⠁⢀⠇⠀⣉⡤⠔⢛⣧⡤⠤⠤⠤⠤⠤⠿⢷⣦⣶⣦⣤⣤⠄" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣯⣤⣀⡉⠒⠀⣹⠶⠤⣼⣄⣾⠔⠋⠁⣀⡤⠞⢁⣀⣠⠤⠶⠶⠿⣭⣉⠙⢧⡀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⣤⣶⡟⠋⠉⣉⣉⣉⠛⠛⠷⣶⡃⢀⡤⠘⡿⠓⢶⣬⠥⠔⠒⠒⠚⠛⠶⢶⣦⠀⠀⠀⠈⠉⠛⠿⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⢠⡼⠋⠁⣠⣼⣧⣠⣤⠴⠶⠶⠾⢷⣆⣀⣴⠃⢷⣀⡧⢤⣗⡒⠶⠤⠀⠀⠻⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⡴⠋⢀⡴⠋⠀⠉⠉⠀⠀⠀⠀⠀⢀⡞⠁⠀⢉⡿⠛⣿⢀⢦⡀⠉⢳⣶⠶⠶⢤⣄⡈⠙⠶⣄⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⣼⠁⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡎⠀⠀⠀⡼⠀⠀⠛⠻⣆⠳⡀⠘⣏⠁⠀⠀⠀⠉⠙⠓⠮⢿⣦⡀⠀⠀⠀" << std::endl;
	file << "⠀⣇⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠉⠙⠒⢲⡇⠀⠀⠀⠀⠸⡄⢱⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠇⢤⠀⠀⢸⠁⠀⠀⠀⠀⠀⢻⠀⠃⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⡀⠀⠘⠀⢸⠀⠀⠀⠀⠀⠀⢸⡆⢀⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠉⠉⠉⠉⠙⡇⠀⠀⠀⠀⠀⣸⣧⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠤⠀⠀⠀⠀⢷⠀⠀⠀⠀⠀⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⠉⠀⠀⠀⠘⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀⣀⣀⣠⠼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⠋⠉⠁⠀⢀⡀⠻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⠀⠀⠀⠈⠉⠀⠘⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⣀⣀⢹⡀⣰⠛⢧⣠⢄⣀⣬⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣿⠻⡌⠻⠿⠃⠀⠈⠁⠈⠁⠸⠋⢹⡷⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠲⠶⠒⠒⠚⠛⠛⠛⠛⠓⠓⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	file << std::endl;
	file.close();	
}
