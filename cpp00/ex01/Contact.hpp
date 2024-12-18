

#ifndef CONTACT_H
#   define CONTACT_H

#include <iostream>
// #include "PhoneBook.hpp"

class Contact
{
    private:
        std::string  First_Name;
        std::string  Last_Name;
        std::string  Nickname;
        std::string  Phone_Number;
        std::string  Darkest_Secret;
    public:
        Contact(){
            yes = 0;
        }
        ~Contact(){}
        void            Add();
        std::string     getName(std::string name);
        std::string     getIn(std::string str);
        bool            isName(std::string adentro);
        std::string     getPhone(std::string phone);
        bool            isPhone(std::string adentro);
        std::string     set_up_str(std::string str);
        int             contact(int i);
        int             print_contact(int i);
        void            print_contact_details(int index);
        bool            isNot(std::string adentro);

        bool    yes;
};

#endif