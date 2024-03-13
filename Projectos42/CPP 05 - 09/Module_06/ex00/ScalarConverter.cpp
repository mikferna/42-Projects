/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:05:53 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/12 16:42:15 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter( const ScalarConverter& obj ) {
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& obj ) {
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

int isNumber(std::string str) {
    for (std::string::size_type i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}


int isPseudo (std::string str)
{
	if (str.compare("nan") == 0 || str.compare("inf") == 0 || str.compare("-inf") == 0 || str.compare("+inf") == 0)
		return 1;
	if (str.compare("nanf") == 0 || str.compare("inff") == 0 || str.compare("-inff") == 0 || str.compare("+inff") == 0)
		return 1;
	return 0;
}

int isFloatDouble(const std::string& str) {
    try {
        size_t pos = 0;
        std::size_t found = str.find_first_not_of(" \t\n\v\f\r");
        if (found == std::string::npos) {
            return 0;
        }
        if (str[found] == '-' || str[found] == '+') {
            pos = found + 1;
        } else {
            pos = found;
        }
        std::string num = str.substr(pos);
        if (num.back() == 'f' || num.back() == 'F') {
            num.pop_back();
            std::stof(num, &pos);
            if (pos == num.size()) {
                return 1;
            }
        } else {
            std::stod(num, &pos);
            if (pos == num.size()) {
                return 2;
            }
        }
    } catch (const std::exception&) {
    }
    return 0;
}

int get_type(std::string str)
{
    if (str.empty())
        return -1;
	else if (isPseudo(str))
		return 0;
	else if (str.size() == 1 && !isNumber(str))
		return 1;
	else if (isNumber(str))
		return 2;
	else if (isFloatDouble(str) == 1)
		return 3;
	else if (isFloatDouble(str) == 2)
		return 4;
	return -1;
}

void printtype(char c, int i, float f, double d) {
	std::cout << "char: ";
	if (c >= ' ' && c <= '~') {
		std::cout << "'" << c << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: ";
    if (f == static_cast<int>(f)) {
        std::cout << f << ".0f" << std::endl;
    } else {
        std::cout << f << "f" << std::endl;
    }
    std::cout << "double: ";
    if (d == static_cast<int>(d)) {
        std::cout << d << ".0" << std::endl;
    } else {
        std::cout << d << std::endl;
    }
}

void printPseudo (std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str.back() == 'f') {
		std::cout << "float: " << str << std::endl;
	} else {
		std::cout << "float: " << str << "f" << std::endl;
	}
	if (str.back() == 'f') {
		std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
	} else {
		std::cout << "double: " << str << std::endl;
	}
}

void ScalarConverter::convert(std::string str, char& c, int& i, float& f, double& d)
{
	int type = get_type(str);
	switch (type)
	{
		case -1:
			std::cout << "Error: Cadena Indeterminada" << std::endl;
			return;
		case 0:
			printPseudo(str);
			break;
		case 1:
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case 2:
			i = std::stoi(str);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case 3:
			f = std::stof(str);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case 4:
			d = std::stod(str);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<double>(d);
			break;
	}
	if (type != -1 && type != 0)
		printtype(c, i, f, d);
}
