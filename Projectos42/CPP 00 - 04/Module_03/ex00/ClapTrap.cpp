/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:32:33 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/15 11:30:11 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

bool ClapTrap::isDead()
{
	if (ClapTrap::_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return true;
	}
	return false;
}

bool ClapTrap::hasEnergy()
{
	if (ClapTrap::_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left" << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->isDead() && !this->hasEnergy())
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->isDead())
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		if (amount > this->_hit_points)
			this->_hit_points = 0;
		else
			this->_hit_points -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->isDead())
	{
		std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << std::endl;
		this->_energy_points -= 1;
		this->_hit_points += amount;
	}
}
