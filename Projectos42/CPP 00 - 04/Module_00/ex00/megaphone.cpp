/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:47:26 by mikferna          #+#    #+#             */
/*   Updated: 2024/01/17 12:02:06 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string mayus(std::string argv)
{
	for(int i = 0; i < (int)argv.length(); i++)
		argv[i] = toupper(argv[i]);
	return (argv);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		std::cout << mayus(argv[i]);
	std::cout << std::endl;
}
