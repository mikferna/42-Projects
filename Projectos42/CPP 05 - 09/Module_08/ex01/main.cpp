/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:52:51 by mikferna          #+#    #+#             */
/*   Updated: 2024/04/09 13:54:34 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try {
		std::cout << "\033[0;1m\nTEST 1:\n\n\033[0;0m";
		Span S(5);

		S.addNumber(5);
		S.addNumber(-2);
		S.addNumber(3);
		S.addNumber(15);
		S.addNumber(-7);

		std::cout << "min = " << S.shortestSpan() << " max = " << S.longestSpan() << "\n";

		S.addNumber(0);
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << "\n";
	}
	try {
		std::cout << "\033[0;1m\nTEST 2:\n\n\033[0;0m";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << "\n";
	}
	try {
		std::cout << "\033[0;1m\nTEST 3:\n\n\033[0;0m";
		Span sp = Span(5);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << "\n";
	}
	try {
		std::cout << "\033[0;1m\nTEST 4:\n\n\033[0;0m";
		Span sp = Span(5);
		sp.addNumber(2);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << "\n";
	}
	try {
		std::cout << "\033[0;1m\nTEST 5:\n\n\033[0;0m";
		Span sp = Span(100);
		int arr[] = {9555,9769,7496,8686,5071,1583,8263,-9524,8788,-2007,5689,-7775,2825,-7026,6057,743,6840,9540,5667,9985,4826,4748,-5441,-9488,-101,4212,8387,5983,-1038,7851,-6845,1723,444,6486,-1588,-970,-2621,4310,-1417,-2669,3649,6739,7892,272,9960,-6995,5033,335,2780,5857,8842,6636,-9531,4830,2914,9509,7481,1573,8818,7073,-6335,7244,1056,9575,8628,7488,-1572,8566,9884,2094,1744,2041,1238,-2368,6353,9652,1121,-1743,3785,2165,6610,-8943,-3100,3448,4027,6482,5143,659,5482,2063,5514,1088,9344,362,3243,7576,7776,9847,336,-836};
		std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

		sp.addNumber(nums.begin(), nums.end());
		std::cout << "min = " << sp.shortestSpan() << " max = " << sp.longestSpan() << "\n";
	} catch (const std::exception& e) {
		std::cout << "Error : " << e.what() << "\n";
	}
	return 0;
}
