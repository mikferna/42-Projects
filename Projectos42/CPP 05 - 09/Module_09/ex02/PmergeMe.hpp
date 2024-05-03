/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:05:45 by mikferna          #+#    #+#             */
/*   Updated: 2024/04/17 16:02:52 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int>  _deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

        void get_input(char **av);
        void show_vector_before();
        void show_vector_after();
        void show_deque_before();
		void main_one(char **av);

        void mergeInsertionSort(std::vector<int>& arr);
        void mergeInsertionSort(std::deque<int>& arr);
        void insertionSort(std::vector<int>& arr);
        void insertionSort(std::deque<int>& arr);
};

#endif