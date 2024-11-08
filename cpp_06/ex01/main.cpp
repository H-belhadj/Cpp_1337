/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:27:52 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/08 20:57:28 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data D;
    Data *after_cast;
    uintptr_t buffer = 0;
    D.value = 4869;

    std::cout << "before serialize: " << D.value << std::endl;
    buffer = Serializer::serialize(&D);
    std::cout << "after serialize: " << buffer << std::endl;
    after_cast = Serializer::deserialize(buffer);
    std::cout << "after deserialize: " << after_cast->value << std::endl;
}