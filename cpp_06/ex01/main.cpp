/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:27:52 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/26 23:52:28 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    // Step 1: Create a Data object and populate it with some values.
    Data data = {"Sample Name", 123, 456};

    // Display original data to verify the contents
    std::cout << "Original Data:\n";
    std::cout << "Name: " << data._name << "\n";
    std::cout << "num1: " << data.num1 << "\n";
    std::cout << "num2: " << data.num2 << "\n\n";

    // Step 2: Serialize the pointer to `data` (convert pointer to integer).
    uintptr_t serializedPtr = Serializer::serialize(&data);
    std::cout << "Serialized Pointer: " << serializedPtr << "\n\n";

    // Step 3: Deserialize the integer back to a pointer.
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Step 4: Verify that the original and deserialized pointers are the same.
    if (deserializedPtr == &data) {
        std::cout << "Deserialization successful! Pointers match.\n";
    } else {
        std::cout << "Deserialization failed. Pointers do not match.\n";
    }

    return 0;
}
