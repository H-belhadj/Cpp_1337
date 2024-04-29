/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:44:40 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/02/28 18:10:32 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
# include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
    this->Name = "";
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
    std::cout << "Building ScavTrap" << std::endl;

}

ScavTrap::ScavTrap(const std::string newName)
{
    this->Name = newName;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
    std::cout << "Building ScavTrap named " << newName << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    std::cout << "Building ScavTrap named " << Name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        Hit_points = other.Hit_points;
        Energy_points = other.Energy_points;
        Attack_damage = other.Attack_damage;
        std::cout << "ScavTrap named " << Name << " has been assigned!" << std::endl;
    }
    return (*this);
}
ScavTrap::~ScavTrap()
{
    std::cout << "Destroying ScavTrap named " << Name << std::endl; 
}
void  ScavTrap::guardgate()
{
    std::cout << "Scavtrap " << Name << " is now in gatekeeper mode." << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
        std::cout << "ScavTrap " << Name << " can't attack " << target << " due to low energy or nno hit points!" << std::endl;
}