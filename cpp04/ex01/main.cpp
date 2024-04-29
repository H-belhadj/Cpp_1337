/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:25:36 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/04/22 18:44:02 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "brain.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    Cat basic;
    {
        Cat tmp = basic;
    }
    Animal* animal[6] = {new Dog(), new Cat(), new Dog(), new Cat(), new Dog(), new Cat()};
    int index = 0;
    while (index < 6) {
        delete animal[index];
        index++;
    }
    return 0;
}