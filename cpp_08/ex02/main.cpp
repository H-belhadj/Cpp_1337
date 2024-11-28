/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:02:35 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/25 16:02:35 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "the front is: " << mstack.front() << std::endl;
	mstack.pop_back();
	std::cout << "the size is: " << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
    std::cout << "===========================\n";
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}    
    std::cout << "============= the copy stack =============\n";

	std::list<int> s(mstack);
    s.pop_back();
    s.push_back(110);
    s.push_front(2002);
    s.sort();
    for(std::list<int>::iterator it = s.begin() ; it != s.end() ; ++it)
        std::cout << *it << std::endl;
    s.clear();
    std::cout << "============= the copy stack after the clear=============\n";
    if (s.empty())
            std::cout << "Dor 100 " << std::endl;
    for(std::list<int>::iterator it = s.begin() ; it != s.end() ; ++it)
    {
       
            std::cout << *it << std::endl;

    }
	return 0;
}