/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:13 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/06 14:16:36 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	char c;
	int i;
	float f;
	double d;
	if (ac > 1)
		ScalarConverter::convert(av[1], c, i, f, d);
	return 0;
}
