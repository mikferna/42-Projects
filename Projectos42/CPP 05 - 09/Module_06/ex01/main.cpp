/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:23:03 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/07 13:02:55 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	{
		Data D;
		Data *res;
		D.i = -21;

		res = Serializer::deserialize(Serializer::serialize(&D));
		std::cout << "\nTEST 1:\n";
		std::cout << "  before: " << D.i << "\n";
		std::cout << "  after:  " << res->i << "\n";
	}
	{
		uintptr_t i = 42;
		uintptr_t o;

		o = Serializer::serialize(Serializer::deserialize(i));
		std::cout << "\nTEST 2:\n";
		std::cout << "  before: " << i << "\n";
		std::cout << "  after:  " << o << "\n";
	}
	std::cout << "\n";
	return 0;
}