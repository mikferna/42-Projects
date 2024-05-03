/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:39:12 by mikferna          #+#    #+#             */
/*   Updated: 2024/04/17 12:16:47 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const std::string &str)
{
	_str = str;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	_str = other._str;
	_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::parse()
{
	std::stringstream ss(_str);
	std::string token;
	while (std::getline(ss, token, ' '))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
			operate(token);
		else if (std::isdigit(token[0]))
		{
			if (atof(token.c_str()) < 0 || atof(token.c_str()) > 9)
			{
				std::cout << "Error: Invalid value" << std::endl;
				return ;
			}
			_stack.push(std::stof(token));
		}
		else
		{
			std::cout << "Error: invalid token" << std::endl;
			return;
		}
	}
	printResult();
}

void RPN::operate(const std::string &op)
{
	float a;
	float b;
	float result;

	if (_stack.size() < 2)
	{
		std::cout << "Error: not enough operands" << std::endl;
		return;
	}
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	else if (op == "/")
	{
		if (b == 0)
		{
			std::cout << "Error: division by zero" << std::endl;
			return;
		}
		result = a / b;
	}
	else if (op == "%")
	{
		if (b == 0)
		{
			std::cout << "Error: modulo by zero" << std::endl;
			return;
		}
		result = std::fmod(a, b);
	}
	_stack.push(result);
}

void RPN::printResult()
{
	if (_stack.size() != 1)
		std::cout << "Error: too many operands" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}
