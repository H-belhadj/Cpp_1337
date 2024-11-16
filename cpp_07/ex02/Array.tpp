/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:27:21 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 17:27:21 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "Array.hpp"   

template <typename Type>
Array<Type>::Array() : _array(NULL), _size(0)
{}
template <typename Type>
Array<Type>::Array(unsigned int n) : _array(new Type[n]), _size(n)
{}
template <typename Type>
Array<Type>::Array(Array const &obj) : _array(NULL), _size(0)
{
    *this = obj;
}
template <typename Type>
Array<Type> &Array<Type>::operator=(Array const &rhs)
{
    if (this != &rhs)
    {
        if (_array)
            delete[] _array;
        _array = new Type[rhs._size];
        _size = rhs._size;
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = rhs._array[i];
    }
    return *this;
}

template <typename Type>
Array<Type>::~Array()
{
    if (_array)
        delete[] _array;
}
template <typename Type>
unsigned int Array<Type>::size() const
{
    return _size;
}

template <typename Type>
Type &Array<Type>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfLimitsException();
    return _array[index];
}

template <typename Type>
const Type &Array<Type>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfLimitsException();
    return _array[index];
}