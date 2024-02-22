/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:20:54 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/02 11:18:19 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int raw ) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = raw << this->_frac;
}

Fixed::Fixed( const float raw ) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(raw * (1 << this->_frac));
}

Fixed::Fixed( const Fixed& obj ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& obj ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits ( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_value / (1 << this->_frac));
}

int Fixed::toInt( void ) const {
	return (this->_value >> this->_frac);
}

std::ostream& operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}

bool Fixed::operator>( const Fixed& obj ) const {
	return (this->_value > obj.getRawBits());
}

bool Fixed::operator<( const Fixed& obj ) const {
	return (this->_value < obj.getRawBits());
}

bool Fixed::operator>=( const Fixed& obj ) const {
	return (this->_value >= obj.getRawBits());
}

bool Fixed::operator<=( const Fixed& obj ) const {
	return (this->_value <= obj.getRawBits());
}

bool Fixed::operator==( const Fixed& obj ) const {
	return (this->_value == obj.getRawBits());
}

bool Fixed::operator!=( const Fixed& obj ) const {
	return (this->_value != obj.getRawBits());
}

Fixed Fixed::operator+( const Fixed& obj ) const {
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-( const Fixed& obj ) const {
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*( const Fixed& obj ) const {
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/( const Fixed& obj ) const {
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed& Fixed::operator++( void ) {
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--( void ) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	return (a > b ? a : b);
}

Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	return (a < b ? a : b);
}
