/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:00:54 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/13 16:42:21 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T const &x){
	std::cout << x << std::endl;
}

int main(){
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 2, print);
	return 0;
}
