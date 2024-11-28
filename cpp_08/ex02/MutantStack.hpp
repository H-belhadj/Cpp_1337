/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:52:07 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/15 17:52:07 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        
        MutantStack(const MutantStack &other)
        {
            *this = other;
        }

        MutantStack& operator=(const MutantStack &other)
        {
            this->c = other.c;
            return *this;
        }

        ~MutantStack() {}

        typedef typename std::stack<T>::iterator iterator;
        typedef typename std::stack<T>::const_iterator const_iterator;
        
        iterator begin()
        { 
            return this->c.begin();
        }
        iterator end()
        { 
            return this->c.end();
        }
        const_iterator begin() const
        { 
            return this->c.begin(); 
        }
        const_iterator end() const
        { 
            return this->c.end();
        }
};

#endif
