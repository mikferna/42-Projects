/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:32:35 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/14 13:38:11 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap F("Fer");
	F.showAttributes();
	F.attack("Air");
	F.showAttributes();
	F.highFivesGuys();
	FragTrap F2("Fer2");
	F2 = F;
	F.takeDamage(20);
	F.showAttributes();
	F2.showAttributes();
	return 0;
}
