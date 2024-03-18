/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:29:15 by mikferna          #+#    #+#             */
/*   Updated: 2024/03/18 12:22:24 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
#define Array_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T * _array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		~Array();
		Array &operator=(const Array<T> &other);
		T &operator[](int i) const;
		unsigned int size() const;
		class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Index is out of bounds";}
    };
};


template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](int i) const
{
	if (i < 0 || i >= (int)_size)
		throw OutOfBoundsException();
	return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
