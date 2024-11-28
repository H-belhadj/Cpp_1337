/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:24:37 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/15 17:24:37 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    //test1 : empty cntr
    std::vector<int> elgrandetoto;
    std::cout << "======elgrandetoto vector======" << std::endl;
    try
    {
        easyfind(elgrandetoto, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //test2: one element
    std::vector<int> madd;
    std::cout << "======Madd vector======" << std::endl;
    madd.push_back(3);
    try
    {
        easyfind(madd, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //test3: multiple element
    std::vector<int> stormy;
    std::cout << "======Stormy vector======" << std::endl;
    stormy.push_back(1);
    stormy.push_back(2);
    stormy.push_back(3);
    stormy.push_back(4);
    stormy.push_back(50);
    try
    {
        easyfind(stormy, 50);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
