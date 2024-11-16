/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:27:03 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 17:27:03 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "whatever.hpp"

template <typename Type>
void swap(Type & a, Type & b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}
template <typename Type>
Type min(Type a, Type b)
{
    return (a < b ? a : b);
}
template <typename Type>
Type max(Type a, Type b)
{
    return (a > b ? a : b);
}
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}