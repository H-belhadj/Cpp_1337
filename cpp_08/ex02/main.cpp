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
#include <list>
#include <iosteam>

void test_mutant_stack()
{
    std::cout << "=== Testing MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Testing iterators
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Elements: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Testing reverse iterators
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Reverse elements: ";
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;
}

void test_list() {
    std::cout << "\n=== Testing std::list ===" << std::endl;

    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << "Back element: " << list.back() << std::endl;

    list.pop_back();
    std::cout << "Size after pop: " << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    // Testing iterators
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    std::cout << "Elements: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Testing reverse iterators
    std::list<int>::reverse_iterator rit = list.rbegin();
    std::list<int>::reverse_iterator rite = list.rend();
    std::cout << "Reverse elements: ";
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;
}

int main() {
    test_mutant_stack();
    test_list();
    return 0;
}
