/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:39:18 by mikferna          #+#    #+#             */
/*   Updated: 2024/04/22 13:40:06 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class RPN
{
	private:
		std::stack<float> _stack;
		std::string _str;
	public:
		RPN();
		RPN(const std::string &str);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void printResult();
		void operate(const std::string &op);
		void parse();
};

#endif