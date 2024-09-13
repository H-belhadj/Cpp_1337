/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:44 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/13 08:14:11 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int	main(){
	try
	{
		Bureaucrat	agent = Bureaucrat("siham", 100);
		Form file = Form("FBI", 101, 3);
		std::cout << file << std::endl ;
		agent.signForm(file);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}