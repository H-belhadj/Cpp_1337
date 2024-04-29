/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:18:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/26 11:06:10 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "copy assignment operator called" << std::endl;
    if(this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    value = num << bits;
}
Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(nb*(1 << bits));
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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