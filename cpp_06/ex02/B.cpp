/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:24:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/08 01:28:44 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(){}

B& B::operator=(const B& rhs)
{
    (void)rhs;
    return (*this);
}

B::B(const B& obj)
{
    *this = obj;    
}
B::~B(){}