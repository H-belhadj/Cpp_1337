/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:54:15 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/08 01:39:18 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

typedef std::string str;

class Base
{
    public:
        virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
