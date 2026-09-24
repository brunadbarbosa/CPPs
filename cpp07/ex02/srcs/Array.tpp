/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

/* new T[n]() value-initializes: ints are 0, classes use their default ctor */
template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n) {
	if (n > 0)
		this->_elements = new T[n]();
}

/* deep copy: the copy owns its own memory */
template <typename T>
Array<T>::Array(Array const &other) : _elements(NULL), _size(0) {
	*this = other;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_elements;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this == &other)
		return (*this);
	T *newElements = NULL;
	if (other._size > 0) {
		newElements = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++)
			newElements[i] = other._elements[i];
	}
	delete[] this->_elements;
	this->_elements = newElements;
	this->_size = other._size;
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw OutOfBoundsException();
	return (this->_elements[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size)
		throw OutOfBoundsException();
	return (this->_elements[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
	return ("Array: index out of bounds");
}

#endif
