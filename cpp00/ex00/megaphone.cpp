/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:54:10 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/12/15 23:20:24 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    int i = 0;
    while(++i < argc)
    {
        char *arr = argv[i];
        int x = 0;
        int len = strlen(arr);
        while(x < len)
            putchar(toupper(arr[x++]));
    }
    return(0);
}