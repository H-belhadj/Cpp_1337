/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:28:51 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/08 21:30:45 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip> 

int	main(int ac, char **av)
{
	// float f = 42f;
	// std::cout << f << std::endl;
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "Wrong arguments" << std::endl;
}