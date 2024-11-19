/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:04:08 by clundber          #+#    #+#             */
/*   Updated: 2024/11/19 11:05:08 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Array.hpp"

//constructors and destructor
template<typename T>
Array<T>::Array() : _len(0)
{
	_array = new T[0];
}

template<typename T>
Array<T>::Array(uint _newLen) : _len(_newLen)
{
	_array = new T[_newLen];
	for (uint i = 0; i < _newLen; i++)
		_array[i] = T();
}

template<typename T>
Array<T>::Array(Array& other)
{
	this->_len = other._len;
	this->_array = new T[_len];
	for (uint i = 0; i < _len; i++)
	{
		this->_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete [] _array;
}

//overloads
template<typename T>
Array<T>& Array<T>::operator=(Array& other)
{
	if (this != &other)
	{
		this->_len = other._len;
		delete [] this->_array;
		this->_array = new T[_len];
		for (uint i = 0; i < _len; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

//methods
template<typename T>
uint Array<T>::size()
{
	return (_len);
}

template<typename T>
T& Array<T>::operator[](uint index)
{
	if (index < _len)
		return (_array[index]);
	else
		throw std::invalid_argument("index out of memory");
}

template<typename T>
const T& Array<T>::operator[](uint index) const
{
	if (index < _len)
		return (_array[index]);
	else
		throw std::invalid_argument("index out of memory");
}

