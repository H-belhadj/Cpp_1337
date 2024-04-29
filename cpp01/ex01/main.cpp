/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:05:14 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/19 15:48:55 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int	main(void)
{
	Zombie *z = zombieHorde(50, "SPIDER MAN");
	if (z)
	{
		for (int i = 0; i < 50 ; i++)
			z[i].announce();
		delete [] z;
	}
	return 0;
}