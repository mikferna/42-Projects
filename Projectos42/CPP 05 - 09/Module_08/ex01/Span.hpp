/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:53:01 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/19 13:28:22 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};



#endif