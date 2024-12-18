/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:24:51 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/08 01:28:49 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(){}

C& C::operator=(const C& rhs)
{
    (void)rhs;
    return (*this);
}

C::C(const C& obj)
{
    *this = obj;    
}
C::~C(){}