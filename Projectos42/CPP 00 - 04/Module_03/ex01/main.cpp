/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:32:35 by mikferna          #+#    #+#             */
/*   Updated: 2024/02/15 11:31:58 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap S("Susan");
	ScavTrap I(S);
	ClapTrap J("Jhon");
	S.showAttributes();
	J.showAttributes();
	S.attack("Jhon");
	J.takeDamage(5);
	S.showAttributes();
	J.showAttributes();
	J.takeDamage(20);
	S.beRepaired(40);
	S.showAttributes();
	J.showAttributes();
	return 0;
}
