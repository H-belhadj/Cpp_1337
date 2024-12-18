

#include "PhoneBook.hpp"
#include "Contact.hpp"

void    PhoneBook::Add_value()
{
    static int index;
    int i = index % 8;
    contacts[i].Add();
    index++;
    std::cout << "the contact added whit seccefuly" << std::endl;
}

void    PhoneBook::disPlay()
{
    int i = -1;
    std::cout << "=============================================" << std::endl;
    std::cout << "|   INDEX  |First Name| Last Name| NickName |" <<std::endl;
    while(++i < 8)
    {
        if(contacts[i].print_contact(i))
            break;
    }
    std::cout << "=============================================" <<std::endl;
}
int     PhoneBook::give_idx()
{
    std::string tmp;
    int idx;
    while(1)
    {
        std::cout << "chose one index -_- >>";
        std::getline(std::cin, tmp);
        if(std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if(tmp.length() == 1 && std::isdigit(tmp[0]))
        {
            idx = tmp[0] - '0';
            break;
        }
    }
    return (idx);
}

void    PhoneBook::search()
{
    int index;
    disPlay();
    int i = -1;
    
    while(++i < 8)
    {
        std::string tmp;
        if(contacts[i].yes == 0)
            break;
    }
    if(i == 0)
    {
        std::cout << "SORRY List is emty ." << std::endl;;
        return ;
    }
    while(1)
    {
        index = give_idx();
        if(index < i)
        {
            contacts[index].print_contact_details(index);
            break;
        }
    }
}
