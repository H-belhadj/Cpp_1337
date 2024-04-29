/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zomebieHorde.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:04:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/06 19:04:57 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string  name)
{
    Zombie  *Z = new Zombie[N];
    int i = 0;
    while(i < N)
    {
        Z[i].setName(name);
        i++;
    }
    return (Z);
}