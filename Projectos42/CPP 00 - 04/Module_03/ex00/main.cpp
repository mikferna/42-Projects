/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:32:35 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/15 11:23:35 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout <<  std::endl << "TEST 2:" << std::endl;
	ClapTrap A("Ana"), B("Bob");
	A.attack("Bob");
	B.beRepaired(10);
	ClapTrap C(B);
	B.takeDamage(10);
	C.takeDamage(10);
	C.takeDamage(1);
	return 0;
}
