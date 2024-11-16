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

#include "iter.hpp"

template <typename Type>
void iter(Type *array, int size, void (*func)(Type const &))
{
    int i = 0;
    while(i++ < size)
        func(array[i]);
}
template <typename Type>
void print(Type const &val)
{
    std::cout << val << std::endl;
}
int main()
{
    // Test 1: Using iter with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Integer array:" << std::endl;
    iter(intArray, intSize, print);

    std::cout << "-------------------" << std::endl;

    // Test 2: Using iter with an array of strings
    std::string strArray[] = {"Hello", "World", "from", "iter"};
    int strSize = sizeof(strArray) / sizeof(strArray[0]);
    std::cout << "String array:" << std::endl;
    iter(strArray, strSize, print);

    std::cout << "-------------------" << std::endl;

    // Test 3: Using iter with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Double array:" << std::endl;
    iter(doubleArray, doubleSize, print);

    return 0;
}