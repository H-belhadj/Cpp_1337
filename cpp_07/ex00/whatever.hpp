/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:27:08 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 17:27:08 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>

typedef std::string str;

template <typename Type>
void swap(Type & a, Type & b);

template <typename Type>
Type min(Type a, Type b);

template <typename Type>
Type max(Type a, Type b);

#endif