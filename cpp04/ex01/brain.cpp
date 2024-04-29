/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:49 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/04/25 18:05:43 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}
Brain& Brain::operator=(const Brain &other)
{
    int i = 0;
    if(this != &other)
    {
        while(i < 100)
        {
            this->ideas[i] = other.ideas[i];
            i++;
        }
    }
    std::cout << "Brain Copy Assignment operator called" << std::endl;
    return (*this);
}
Brain::~Brain()
{
    std::cout << "Brain Default destructor called" << std::endl;
}
