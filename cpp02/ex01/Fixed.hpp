/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:18:59 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/25 15:07:44 by hbelhadj         ###   ########.fr       */
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
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream& COUT, Fixed const &i);

#endif