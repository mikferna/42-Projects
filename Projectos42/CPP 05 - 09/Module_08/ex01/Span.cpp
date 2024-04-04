/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:53:09 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/21 13:59:00 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_vec = rhs._vec;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (this->_vec.size() == this->_n)
		throw Span::FullSpanException();
	this->_vec.push_back(number);
}

int Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw Span::NoSpanException();
	std::vector<int> tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw Span::NoSpanException();
	std::vector<int> tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

const char *Span::NoSpanException::what() const throw()
{
	return "No span to find";
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}
