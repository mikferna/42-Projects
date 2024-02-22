/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:20:52 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/02 11:11:05 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _frac = 8;
	public:
		Fixed();
		Fixed( const Fixed& obj );
		Fixed( const int raw );
		Fixed( const float raw );

		~Fixed();

		int getRawBits( void ) const;
		void setRawBits ( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>( const Fixed& obj ) const;
		bool operator<( const Fixed& obj ) const;
		bool operator>=( const Fixed& obj ) const;
		bool operator<=( const Fixed& obj ) const;
		bool operator==( const Fixed& obj ) const;
		bool operator!=( const Fixed& obj ) const;

		Fixed operator+( const Fixed& obj ) const;
		Fixed operator-( const Fixed& obj ) const;
		Fixed operator*( const Fixed& obj ) const;
		Fixed operator/( const Fixed& obj ) const;

		Fixed& operator=( const Fixed& obj );
		Fixed& operator++( void );
		Fixed& operator--( void );
		Fixed operator++( int );
		Fixed operator--( int );

		static Fixed& max( Fixed& a, Fixed& b );
		static const Fixed& max( const Fixed& a, const Fixed& b );
		static Fixed& min( Fixed& a, Fixed& b );
		static const Fixed& min( const Fixed& a, const Fixed& b );
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif