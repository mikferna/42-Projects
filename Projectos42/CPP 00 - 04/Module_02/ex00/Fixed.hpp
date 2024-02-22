/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:45:42 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/31 13:36:07 by mikferna         ###   ########.fr       */
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
		~Fixed();
		Fixed& operator=( const Fixed& obj );
		int getRawBits( void ) const;
		void setRawBits ( int const raw );
};

#endif