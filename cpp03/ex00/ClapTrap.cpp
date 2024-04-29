/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:35:55 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/02/29 16:46:16 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(""), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap has been created!" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), Hit_points(10), Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap named "  << Name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : Name(other.Name), Hit_points(other.Hit_points), Energy_points(other.Energy_points), Attack_damage(other.Attack_damage)
{
    std::cout << "ClapTrap named " << Name << " has been created by copying " << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        Hit_points = other.Hit_points;
        Energy_points = other.Energy_points;
        Attack_damage = other.Attack_damage;
        std::cout << "ClapTrap named " << Name << " has been assigned!" << std::endl;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap named " <<  Name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy_points > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
        Energy_points--;
    }
    else
        std::cout << "ClapTrap " << Name << " can't attack " << target << " due to low energy or no hit points!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points > 0)
    {
        Hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
        if (Hit_points <= 0)
            std::cout << "ClapTrap " << Name << " DIE!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " has already been destroyed!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit_points > 0)
    {
        Hit_points += amount;
        Energy_points--;
        std::cout << "ClapTrap " << Name << " has been repaired for " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " can't be repaired because it has already detroyes!" << std::endl;
}


std::string ClapTrap::get_name()const{
    return (this->Name);
}
int ClapTrap::get_Hit_pointer()const{
    return (this->Hit_points);
}
int ClapTrap::get_Energy_points()const{
    return (this->Energy_points);
}
int ClapTrap::get_Attack_damage()const{
    return (this->Attack_damage);
}

std::ostream& operator<<(std::ostream& COUT, ClapTrap const &i)
{
    COUT << i.get_name() << std::endl;
    COUT << i.get_Hit_pointer() << std::endl;
    COUT << i.get_Energy_points() << std::endl;
    COUT << i.get_Attack_damage() << std::endl;
    return (COUT);
}