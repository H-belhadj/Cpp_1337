/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:46:12 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/15 17:46:12 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &src)
{
    *this = src;
}
Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->_maxSize = src._maxSize;
        this->_vec = src._vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_vec.size() >= _maxSize)
        throw FullException();
    _vec.push_back(n);
}

int Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw NoSpanException();

    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 2; i < tmp.size(); ++i)
    {
        int span = tmp[i] - tmp[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw NoSpanException();

    int maxElement = *std::max_element(_vec.begin(), _vec.end());
    int minElement = *std::min_element(_vec.begin(), _vec.end());
    return maxElement - minElement;
}
