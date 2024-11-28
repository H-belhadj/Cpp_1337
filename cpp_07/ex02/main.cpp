/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:27:27 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 17:27:27 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    // Test 1: Creating an empty array
    Array<int> arr1;
    std::cout << "Array 1 size: " << arr1.size() << std::endl;

    // Test 2: Creating an array of 5 integers
    Array<int> arr2(5);
    std::cout << "Array 2 size: " << arr2.size() << std::endl;

    // Initializing array elements
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        arr2[i] = i * 2; // Assign values to the array elements
    }

    // Output array elements
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }

    // Test 3: Accessing out-of-range index (throws exception)
    try
    {
        arr2[10] = 20;  // Throws std::exception if the index is out of bounds
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 4: Const array for read-only access
    Array<int> constArr(5);
    for (unsigned int i = 0; i < arr2.size(); i++)
    {
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    }
    try
    {
        constArr[0] = 10;
        int value = constArr[3];
        std::cout << "constArr[3] = " << value << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}