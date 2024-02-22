/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:15:19 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/20 13:36:37 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Guau guau" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	_type = copy._type;
}

Dog &Dog::operator=(const Dog &other)
{
	_type = other._type;
	return (*this);
}
