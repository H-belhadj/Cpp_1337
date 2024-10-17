/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:44 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/15 17:03:19 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int	main(){
	try
	{
		Bureaucrat	agent = Bureaucrat("haitam", 10);
		std::cout << agent << std::endl;
		Form file = Form("FBI", 10, 1);
		std::cout << file << std::endl ;
		agent.signForm(file);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}