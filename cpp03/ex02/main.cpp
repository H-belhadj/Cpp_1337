/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:19:58 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/02/28 18:19:35 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int	main(){
	FragTrap a("chinwi");
	FragTrap b;
	b = a;
	std::cout << "===================================" << std::endl;
	b.attack("bilal");
	a.attack("ostore");
	std::cout << "===================================" << std::endl;
    b.takeDamage(10);
    b.highFivesGuys();
	std::cout << "===================================" << std::endl;
}
