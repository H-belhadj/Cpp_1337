/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:44:37 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/02/29 16:49:11 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

    ClapTrap clap("pedri");
    clap.attack("alaba");
    clap.takeDamage(30);
    clap.beRepaired(20);
    std::cout << "=============================" << std::endl;
    ScavTrap scav("gavi");
    scav.attack("camavinga");
    scav.guardgate();
}