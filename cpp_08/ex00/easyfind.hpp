/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:47:48 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/26 19:47:48 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class Error : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "The value was not found.";
        }
};

template <typename T>
void easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it != container.end())
        std::cout << "Value [" << value << "] found in the container." << std::endl;
    else
        throw Error();
}

#endif
