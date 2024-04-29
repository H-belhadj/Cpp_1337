/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:48:29 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/12/26 03:22:47 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string cmd;
    PhoneBook phonebook;
    while(1)
    {
        std::cout << "Enter a Command a Primo [ADD, SEARCH, EXIT] >>>>> ";
        std::getline(std::cin, cmd);
        if(std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if(cmd == "ADD")
            phonebook.Add_value();
        else if (cmd == "SEARCH")
            phonebook.search();
        else if(cmd == "EXIT")
            return(0);
    }
    return (0);
}