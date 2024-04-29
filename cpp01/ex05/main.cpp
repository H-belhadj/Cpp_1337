/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:02:49 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/06 19:02:50 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    if(argc == 2)
        harl.complain(argv[1]);
    else
        std::cout << "Wrong , enter your level\n";
    return(0);
}