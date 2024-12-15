#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj)
{ 
    *this = obj;
}

RPN &RPN::operator=(const RPN &rhs)
{
    (void)rhs;
    return *this;
}

RPN::~RPN() {}

bool RPN::numcheck(const std::string &str)
{
    return str.length() == 1 && isdigit(str[0]);
}
bool RPN::opcheck(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::calc(const std::string &str)
{
    std::stack<int> stack;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            stack.push(str[i] - '0'); 
        else if (opcheck(str[i]))
        {
            if (stack.size() < 2) 
            {
                std::cerr << "Invalid expression: not enough operands for operator " << str[i] << std::endl;
                return;
            }

            int a = stack.top(); 
            stack.pop();
            int b = stack.top(); 
            stack.pop();

           
            if (str[i] == '+')
                stack.push(b + a);
            else if (str[i] == '-')
                stack.push(b - a);
            else if (str[i] == '*')
                stack.push(b * a);
            else if (str[i] == '/')
            {
                if (a == 0)
                {
                    std::cerr << "Error: division by zero" << std::endl;
                    return;
                }
                stack.push(b / a);
            }
        }
        else if (str[i] != ' ')
        {
            std::cerr << "Invalid expression: invalid character " << str[i] << std::endl;
            return;
        }
    }

    if (stack.size() == 1) 
        std::cout << "Result: " << stack.top() << std::endl;
    else
        std::cerr << "Invalid expression: too many or too few operands" << std::endl;
}
