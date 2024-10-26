/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:27:48 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/26 22:36:56 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct e_type
{
    std::string _name;
    int num1;
    int num2;
}d_type;

typedef unsigned long uintptr_t;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& obj);
        Serializer& operator=(const Serializer& obj);
        ~Serializer();
    public:
        static uintptr_t serializer(d_type *ptr);
        static d_type* deserialize(uintptr_t raw);
};

#endif