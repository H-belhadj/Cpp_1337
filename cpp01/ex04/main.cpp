/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:52:25 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/01/19 15:37:50 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cout << "please enter 3 argument" << std::endl;
        return (1);
    }
    if (std::string(argv[3]).empty())
    {
        std::cout << "Error: The fourth argument must not be an empty string" << std::endl;
        return (1);
    }

    std::fstream f_1;
    std::fstream f_2;
    std::string name(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);
    std::string txt;
    std::string tmp;
    std::string res;

    name.append(".replace");
    f_1.open(argv[1], std::ios::in);
    f_2.open(name, std::ios::out);

    if(!f_1 || !f_2)
    {
        std::cout << "ERROR" << std::endl;
        return (1);
    }
    while(getline(f_1, tmp))
    {
        txt.append(tmp);
        if(f_1.eof())
            break;
        txt.append("\n");
    }
    size_t start = 0;
    size_t find = txt.find(s1, start);
    while(find !=  std::string::npos)
    {
        res.append(txt, start, find - start);
        res.append(s2);
        start = find + s1.length();
        find = txt.find(s1, start);
    }
    res.append(txt, start, txt.length() - start);

    f_2 << res;

    f_1.close();
    f_2.close();
    return(0);
}