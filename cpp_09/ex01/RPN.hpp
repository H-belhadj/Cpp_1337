#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib> 

class RPN
{
    public:
        RPN();
        RPN(const RPN &obj);
        RPN &operator=(const RPN &rhs);
        ~RPN();
        
        static bool numcheck(const std::string &str);
        static bool opcheck(char c);
        static void calc(const std::string &str);
};

#endif
