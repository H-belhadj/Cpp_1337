/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:25:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/04/22 15:04:17 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy Assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::setType(std::string type)
{
    std::cout << "Animal SetType called" << std::endl;
    this->type = type;
}

std::string Animal::getType() const
{
    std::cout << "Animal GetType called" << std::endl;
    return this->type;
}
void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}