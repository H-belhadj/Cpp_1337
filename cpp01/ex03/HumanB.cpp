/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:03:31 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/06 19:03:32 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if(weapon)
        std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attack with No weapon " << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}