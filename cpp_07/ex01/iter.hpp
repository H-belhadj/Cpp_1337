/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:26:47 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/11/16 17:26:47 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename Type>
void iter(Type *array, int size, void (*func)(Type const &));

template <typename Type>
void print(Type const &elem);

#endif