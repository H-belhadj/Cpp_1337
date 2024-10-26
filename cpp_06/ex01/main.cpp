/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:27:52 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/26 23:47:53 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create a Data object with some data
    Data data = {"Example Name", 42, 84};

    // Display original data
    std::cout << "Original Data:\n";
    std::cout << "Name: " << data._name << "\n";
    std::cout << "num1: " << data.num1 << "\n";
    std::cout << "num2: " << data.num2 << "\n\n";

    // Serialize the pointer to `data`
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized pointer (integer representation): " << raw << "\n\n";

    // Deserialize back to a `Data` pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Display deserialized data to confirm it's the same as the original
    std::cout << "Deserialized Data:\n";
    std::cout << "Name: " << deserializedData->_name << "\n";
    std::cout << "num1: " << deserializedData->num1 << "\n";
    std::cout << "num2: " << deserializedData->num2 << "\n";

    return 0;
}
