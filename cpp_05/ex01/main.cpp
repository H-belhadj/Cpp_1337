/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:44 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/18 16:33:45 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int	main(){
	try
	{
		Bureaucrat	agent = Bureaucrat("Haitam", 1);
		// std::cout << agent << std::endl;
		Form file = Form("FBI", 50,333);
		agent.signForm(file);
		std::cout << file << std::endl ;
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}