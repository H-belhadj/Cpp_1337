/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:53 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/26 11:03:53 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if(this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

Fixed::Fixed(const int num)
{
    value = num << bits;
}
Fixed::Fixed(const float nb)
{
    value = roundf(nb * (1 << bits));
}
Fixed::~Fixed()
{
}

int Fixed::getRawBits()const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
float Fixed::toFloat(void) const
{
    return ((float)value / (1 << bits));
}

int Fixed::toInt(void) const
{
    return (value >> bits);
}

std::ostream& operator<<(std::ostream& COUT, Fixed const &i)
{
	COUT << i.toFloat();
	return (COUT);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->getRawBits() < other.getRawBits());
}	

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return(Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return(Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return(Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return(Fixed(this->toFloat() / other.toFloat()));
}

Fixed&  Fixed::operator++()
{
    ++value;
    return (*this);
}

Fixed&  Fixed::operator--()
{
    --value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++value;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --value;
    return tmp;
}

Fixed& Fixed::min(Fixed& x, Fixed& y)
{
    if(x.getRawBits() > y.getRawBits())
        return(y);
    return(x);
}
const  Fixed& Fixed::min(const Fixed& x, const Fixed& y)
{
    if(x.getRawBits() > y.getRawBits())
        return(y);
    return(x);
}
Fixed& Fixed::max(Fixed& x, Fixed& y)
{
    if(x.getRawBits() > y.getRawBits())
        return(x);
    return(y);
}
const  Fixed& Fixed::max(const Fixed& x, const Fixed& y)
{
    if(x.getRawBits() > y.getRawBits())
        return(x);
    return(y);
}