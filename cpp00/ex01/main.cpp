

#include "PhoneBook.hpp"

int main()
{
    std::string cmd;
    PhoneBook phonebook;
    while(1)
    {
        std::cout << "Enter a Command a Primo [ADD, SEARCH, EXIT] >>>>> ";
        std::getline(std::cin, cmd);
        if(std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if(cmd == "ADD")
            phonebook.Add_value();
        else if (cmd == "SEARCH")
            phonebook.search();
        else if(cmd == "EXIT")
            return(0);
    }
    return (0);
}