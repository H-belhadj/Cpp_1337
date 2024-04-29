/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:04:51 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/07 13:28:35 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{    
}

HumanA::~HumanA()

{}

void HumanA::attack()
{
    std::cout << this->name << " attack whit their " << weapon.getType() << std::endl;
}