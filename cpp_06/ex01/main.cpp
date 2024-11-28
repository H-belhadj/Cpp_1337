/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:27:52 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/22 19:56:42 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Bad Arguments\n";
        return 1;
    }

    Data D;
    D.value = std::atoi(argv[1]);  // Safely convert to int
    
    std::cout << "Before serialize: " << D.value << std::endl;
    
    // Serialize the address of the object
    uintptr_t buffer = Serializer::serialize(&D);
    std::cout << std::showbase << std::hex << buffer << std::endl;

    // std::cout << "Serialized pointer (uintptr_t): " << buffer << std::endl;
    
    // Deserialize the pointer back to the object
    Data* after_cast = Serializer::deserialize(buffer);
    
    // Access the value of the Data object after deserialization
    std::cout << "After deserialize: " << after_cast->value << std::endl;

    return 0;
}