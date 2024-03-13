/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:03 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/06 13:51:36 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& obj );

		ScalarConverter& operator=( const ScalarConverter& obj );
	public:
		~ScalarConverter();
		static void convert(std::string str, char& c, int& i, float& f, double& d);
};

#endif