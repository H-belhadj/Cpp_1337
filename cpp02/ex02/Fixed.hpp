/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:53:51 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/26 11:03:48 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include<cmath>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    
    public:
        Fixed();
        Fixed(int ref);
        Fixed(float rif);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();    
        float   toFloat( void ) const;//This function converts the fixed-point number to a floating-point representation
        int     toInt( void ) const;//This function converts the fixed-point number to an integer by right-shifting the value by the number of bits
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        //The 6 comparison operators:
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;	
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        //The 4 arithmetic operators:
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        //The 4 increment/decrement:
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        //The 4 public overloaded member functions:
        static  Fixed& min(Fixed& x, Fixed& y);
        static  const  Fixed& min(const Fixed& x, const Fixed& y);
        static  Fixed& max(Fixed& x, Fixed& y);
        static  const Fixed& max(const Fixed& x, const Fixed& y);
};
std::ostream& operator<<(std::ostream& COUT, Fixed const &i);

#endif
