/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:51 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/09 01:23:54 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"
#include <iostream>

int main() {
    try {
        // Test 1: Default constructor
        Array<int> emptyArray;
        std::cout << "Default array size: " << emptyArray.size() << std::endl;

        std::cout << "-------------------" << std::endl;

        // Test 2: Parameterized constructor
        Array<int> intArray(5);
        std::cout << "Initialized array size: " << intArray.size() << std::endl;

        // Test 3: Populate and access elements
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        std::cout << "Array values after assignment:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        std::cout << "-------------------" << std::endl;

        // Test 4: Copy constructor
        Array<int> copiedArray(intArray);
        std::cout << "Copied array values:" << std::endl;
        for (unsigned int i = 0; i < copiedArray.size(); i++) {
            std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
        }

        std::cout << "-------------------" << std::endl;

        // Test 5: Assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array values:" << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
        }

        std::cout << "-------------------" << std::endl;

        // Test 6: Access out-of-bounds index
        std::cout << "Trying to access an out-of-bounds index:" << std::endl;
        std::cout << intArray[10] << std::endl; // This should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
