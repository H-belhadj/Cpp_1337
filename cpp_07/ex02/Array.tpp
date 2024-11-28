/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:30:27 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/24 13:30:27 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (n > 0)
        _array = new T[n];
    else
         _array = nullptr;
}

template <typename T>
Array<T>::Array(const Array& other) : _array(nullptr), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array; 
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;  // Deallocate existing memory
        _size = other._size;
        if (_size > 0)
        {
            _array = new T[_size];  // Allocate new memory
            for (unsigned int i = 0; i < _size; i++)
            {
                _array[i] = other._array[i];  // Copy the elements
            }
        }
        else
            _array = nullptr;
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

#endif
