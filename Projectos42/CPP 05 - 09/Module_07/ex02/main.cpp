/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:14:02 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/18 12:23:32 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define SIZE 10

int main() {

    std::cout << "-----------------------------------------------------" << std::endl;

    Array<float> floatArray(SIZE);
    Array<int> intArray(SIZE);

    for (unsigned int i = 0; i < floatArray.size(); ++i)
        floatArray[i] = static_cast<float>(i) * 1.5f;

    for (unsigned int i = 0; i < intArray.size(); ++i)
        intArray[i] = i * 2;

    std::cout << "Float Array: ";
    for (unsigned int i = 0; i < floatArray.size(); ++i)
        std::cout << floatArray[i] << " ";
    std::cout << std::endl;

    std::cout << "Int Array: ";
    for (unsigned int i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

	try {
		std::cout << "Trying to access an element out of bounds: " << floatArray[SIZE] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    std::cout << "-----------------------------------------------------" << std::endl;

    return 0;
}