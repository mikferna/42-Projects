/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:05:40 by mikferna          #+#    #+#             */
/*   Updated: 2024/04/22 13:30:08 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_deque = rhs._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::get_input(char **av)
{
	int i = 1;
	while (av[i])
	{
		this->_vector.push_back(atoi(av[i]));
		this->_deque.push_back(atoi(av[i]));
		i++;
	}
}

void PmergeMe::show_vector_before()
{
	std::cout << "Vector before: ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::show_vector_after()
{
	std::cout << "Vector after: ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::main_one(char **av)
{
	this->get_input(av);
	if (this->_vector.size() < 2)
	{
		std::cout << "Error: invalid input" << std::endl;
		exit(1);
	}
	struct timeval start;
	struct timeval end;
	this->show_vector_before();
	std::cout << std::endl;
	gettimeofday(&start, NULL);
	this->mergeInsertionSort(this->_vector);
	gettimeofday(&end, NULL);
	this->show_vector_after();
	std::cout << std::endl;
	long long time = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "Time to process a range of "<< _vector.size() << " elements with std::vector : " << time << "us" << std::endl;
	gettimeofday(&start, NULL);
	this->mergeInsertionSort(this->_deque);
	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "Time to process a range of "<< _deque.size() << " elements with std::deque : " << time << "us" << std::endl;
}

void PmergeMe::mergeInsertionSort(std::deque<int> &arr)
{
	std::deque<int> deque1;
	std::deque<int> deque2;

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0)
		{
			deque1.push_back(arr[i]);
		}
		else
		{
			deque2.push_back(arr[i]);
		}
	}
	if (deque1.size() > 1)
	{
		mergeInsertionSort(deque1);
	}
	if (deque2.size() > 1)
	{
		mergeInsertionSort(deque2);
	}
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	while (i < deque1.size() && j < deque2.size())
	{
		if (deque1[i] < deque2[j])
		{
			arr[k++] = deque1[i++];
		}
		else
		{
			arr[k++] = deque2[j++];
		}
	}

	while (i < deque1.size())
	{
		arr[k++] = deque1[i++];
	}
	while (j < deque2.size())
	{
		arr[k++] = deque2[j++];
	}
	insertionSort(arr);
}

void PmergeMe::mergeInsertionSort(std::vector<int> &arr)
{
	std::vector<int> vector1;
	std::vector<int> vector2;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0)
		{
			vector1.push_back(arr[i]);
		}
		else
		{
			vector2.push_back(arr[i]);
		}
	}
	if (vector1.size() > 1)
	{
		mergeInsertionSort(vector1);
	}
	if (vector2.size() > 1)
	{
		mergeInsertionSort(vector2);
	}

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	while (i < vector1.size() && j < vector2.size())
	{
		if (vector1[i] < vector2[j])
		{
			arr[k++] = vector1[i++];
		}
		else
		{
			arr[k++] = vector2[j++];
		}
	}

	while (i < vector1.size())
	{
		arr[k++] = vector1[i++];
	}
	while (j < vector2.size())
	{
		arr[k++] = vector2[j++];
	}
	insertionSort(arr);
}

void PmergeMe::insertionSort(std::vector<int> &arr)
{
	int i, key, j;
	int size = arr.size();
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::insertionSort(std::deque<int> &arr)
{
	int i, key, j;
	int size = arr.size();
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
