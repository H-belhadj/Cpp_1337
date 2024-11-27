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
        // Default constructor
        MutantStack() {}

        // Copy constructor
        MutantStack(const MutantStack &other)
        {
            *this = other;
        }

        // Copy assignment operator
        MutantStack& operator=(const MutantStack &other)
        {
            if (this != &other)
                this->c = other.c;
            return *this;
        }

        // Destructor
        ~MutantStack() {}

        // Define iterator types using the underlying container of std::stack
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        // Iterator functions
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

        reverse_iterator rbegin()
        { 
            return this->c.rbegin();
        }
        reverse_iterator rend()
        { 
            return this->c.rend();
        }
        const_reverse_iterator rbegin() const
        { 
            return this->c.rbegin(); 
        }
        const_reverse_iterator rend() const
        {
            return this->c.rend();
        }
};

#endif
