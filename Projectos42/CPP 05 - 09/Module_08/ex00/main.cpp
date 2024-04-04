/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:15:15 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/19 12:47:49 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	easyfind(vec, 2);
	easyfind(lst, 5);
	easyfind(deq, 7);
	easyfind(vec, 11);
	easyfind(lst, 9);
	easyfind(deq, 24);
	return 0;
}