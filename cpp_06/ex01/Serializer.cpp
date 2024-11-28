/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:27:50 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/21 19:57:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}


Serializer::Serializer(const Serializer& obj)
{
    (void)obj;
}
Serializer& Serializer::operator=(const Serializer& obj)
{
    (void)obj;
    return *this;
}

Serializer::~Serializer(){}
//Convert an object into a byte format that can be stored or transmitted
uintptr_t Serializer::serialize(Data* ptr)
{
    // Cast Data* to uintptr_t using reinterpret_cast
    return reinterpret_cast<uintptr_t>(ptr);
}
//Convert the stored or transmitted byte format back into an object.
Data* Serializer::deserialize(uintptr_t raw)
{
    // Cast uintptr_t back to Data* using reinterpret_cast
    return reinterpret_cast<Data*>(raw);
}