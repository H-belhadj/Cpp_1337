/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:05:36 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/19 15:48:18 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

int	main(void)
{
		Zombie	*z1 = newZombie("Spider_Man");
		z1->announce();
		delete z1;
		randomChump("Iron_man");
		return (0);
}
