/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:57:44 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/09/09 17:37:09 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int	main(){
	try
	{
		Bureaucrat	agent = Bureaucrat("Ayoub", 1);
		Form file = Form("FBI", 4, 3);
		agent.signForm(file);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}