

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact  contacts[8];
    public:
        PhoneBook(){}
        ~PhoneBook(){}
        void    Add_value();
        void    disPlay();
        int     give_idx();
        void    search();
};

#endif
