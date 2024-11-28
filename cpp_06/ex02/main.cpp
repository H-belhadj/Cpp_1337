/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:54:10 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/21 21:45:49 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	Base* x = generate();
	Base* y = generate();

	std::cout << "*x = ";
	identify(x);
	std::cout << "*y = ";
	identify(y);
	
	std::cout << "&x = ";
	identify(*x);
	std::cout << "&y = ";
	identify(*y);
	
	delete x;
	delete y;
}
