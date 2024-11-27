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

#include <algorithm> // For std::find
#include <exception> // For std::exception

// Custom exception class
class Error : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "The value was not found.";
        }
};

// Template function to search for a value in a container
template <typename T>
void easyfind(T& container, int value)
{
    // Use std::find to search for the value in the container
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    // If value is found, print it; otherwise, throw exception
    if (it != container.end())
        std::cout << "Value [" << value << "] found in the container." << std::endl;
    else
        throw Error();
}

#endif // EASYFIND_HPP
