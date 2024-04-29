/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:36:01 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/12/26 20:09:43 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"


bool            Contact::isName(std::string adentro)
{
    int i = 0;
    if(adentro[0] == ' ')
        return(0);
    while(adentro[i])
    {
        if(!isalpha(adentro[i]) && adentro[i] != ' ')
            return(0);
        i++;
    }
    return(1);
}

bool Contact::isNot(std::string adentro)
{
    if(adentro[0] == ' ')
        return(0);
    return (1);
}

bool            Contact::isPhone(std::string adentro)
{
    int i = 0;
    while(adentro[i])
    {
        if(!isdigit(adentro[i]))
            return(0);
        i++;
    }
    return(1);
}


std::string     Contact::getPhone(std::string phone)
{
    std::string adentro = "";
    bool    valid = 0;
    while(valid == 0)
    {
        std::cout << phone;
        std::getline(std::cin, adentro);
        if(std::cin.eof())
        {
            std::cout << "\nGOOD BYE\n";
            exit(0);
        }
        if(std::cin.good() && !adentro.empty() && isPhone(adentro))
            valid = 1;
        else
        {
            std::cin.clear();
            std::cout << "Invalid phone number...\n";
        }
    }
    return (adentro);
}

std::string     Contact::getIn(std::string str)
{
    std::string adentro = "";
    bool    valid = 0;
    while(valid == 0)
    {
        std::cout << str;
        std::getline(std::cin, adentro);
        if(std::cin.eof())
        {
            std::cout << "\nGOOD BYE\n";
            exit(0);
        }
        if(std::cin.good() && !adentro.empty() && isNot(adentro))
            valid = 1;
        else
        {
            std::cin.clear();
            std::cout << "Invalid String...\n";
        }
    }
    return (adentro);
}

std::string     Contact::getName(std::string name)
{
    std::string adentro = "";
    bool    valid = 0;
    while(valid == 0)
    {
        std::cout << name;
        std::getline(std::cin, adentro);
        if(std::cin.eof())
        {
            std::cout << "\nGOOD BYE\n";
            exit(0);
        }
        if(std::cin.good() && !adentro.empty() && isName(adentro))
            valid = 1;
        else
        {
            std::cin.clear();
            std::cout << "Invalid Name...\n";
        }
    }
    return (adentro);
}

std::string Contact::set_up_str(std::string str)
{
    if(str.length() > 10)
        str = str.substr(0, 9).append(".");
    return str;
}

int Contact::print_contact(int i)
{
    if (this->First_Name.length() <= 0) // safe condition
        return (1);
    std::cout << "|==========|==========|==========|==========|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << i;
    std::cout << "|";
    std::cout << std::setw(10) << set_up_str(this->First_Name);
    std::cout << "|";
    std::cout << std::setw(10) << set_up_str(this->Last_Name);
    std::cout << "|";
    std::cout << std::setw(10) << set_up_str(this->Nickname);
    std::cout << "|" << std::endl;
    return (0);
}


void    Contact::Add()
{
    std::cout << "|------------------- NEW CONTACT -------------------|\n";
    this->First_Name = getName("\tFirst_Name\t"); 
    this->Last_Name = getName("\tLast_Name\t"); 
    this->Nickname = getIn("\tNickname\t"); 
    this->Phone_Number = getPhone("\tPhone_Number\t"); 
    this->Darkest_Secret = getIn("\tDarkest_Secret\t"); 
    std::cout << "|---------------------------------------------------|\n";
    yes = 1;
}
void Contact::print_contact_details(int index)
{
    std::cout << "\tindex:              " << index << std::endl;
    std::cout << "\tFirst_Name:         " << this->First_Name << std::endl;
    std::cout << "\tLast_Name:          " << this->Last_Name << std::endl;
    std::cout << "\tNickname:           " << this->Nickname << std::endl;
    std::cout << "\tPhone_Number:       " << this->Phone_Number << std::endl;
    std::cout << "\tDarkest_Secret:     " << this->Darkest_Secret << std::endl;
}