/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:14:58 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/12/03 18:30:07 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac , char *av[])
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "File Not Open" << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange btc;

	btc.readData(av[1]);
}