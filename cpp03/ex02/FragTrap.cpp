/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:19:53 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/02/28 18:20:46 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->Name = "";
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
    std::cout << "Building FragTrap" << std::endl;

}

FragTrap::FragTrap(const std::string& newName)
{
    this->Name = newName;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
    std::cout << "Building FragTrap named " << Name << std::endl;
}
FragTrap::FragTrap(const FragTrap& other)
{
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    std::cout << "Building fragTrap named " << Name << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        Hit_points = other.Hit_points;
        Energy_points = other.Energy_points;
        Attack_damage = other.Attack_damage;
        std::cout << "FragTrap named " << Name << " has been assigned!" << std::endl;
    }
    return (*this);
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap named " << Name << " has been destroyed!" <<std::endl;
}
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
}

