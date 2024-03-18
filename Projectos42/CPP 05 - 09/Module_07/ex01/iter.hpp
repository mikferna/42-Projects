/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:01:35 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/18 12:06:59 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Iter_HPP
#define Iter_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)){
	for (size_t i = 0; i < length; i++){
		f(array[i]);
	}
}

#endif
