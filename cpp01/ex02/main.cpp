


#include <iostream>

int main()
{
    std::string str;

    str = "HI THIS IS MY BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "address string   : " << &str << "| Value of str    : " << str <<std::endl;
    std::cout << "address stringPTR: " << &stringPTR<< "| Value of strPTR : "<< *stringPTR << std::endl;
    std::cout << "address stringREF: " << &stringREF<< "| Value of strREF : "<< stringREF <<std::endl;
}