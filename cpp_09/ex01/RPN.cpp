#include "RPN.hpp"
#include <cstdlib>  // For atoi

RPN::RPN() {}
RPN::RPN(const RPN &obj) { *this = obj; }
RPN &RPN::operator=(const RPN &rhs)
{
    (void)rhs;
    return *this;
}
RPN::~RPN() {}

bool RPN::numcheck(const std::string &str)
{
    // Checks if the string is a valid number (single digit)
    return str.length() == 1 && isdigit(str[0]);
}

bool RPN::opcheck(char c)
{
    // Checks if the character is one of the allowed operators
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::excheck(const std::string &str)
{
    std::stack<int> stack;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            // Push the integer value of the character onto the stack
            stack.push(str[i] - '0');
        }
        else if (opcheck(str[i]))
        {
            // Check if there are at least two operands before applying the operator
            if (stack.size() < 2)
            {
                std::cerr << "Invalid expression: not enough operands for operator " << str[i] << std::endl;
                return false;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            // Perform the corresponding operation
            if (str[i] == '+')
                stack.push(b + a);
            else if (str[i] == '-')
                stack.push(b - a);
            else if (str[i] == '*')
                stack.push(b * a);
            else if (str[i] == '/') {
                if (a == 0) {
                    std::cerr << "Error: division by zero" << std::endl;
                    return false;
                }
                stack.push(b / a);
            }
        }
        else if (str[i] != ' ')
        {
            // If we encounter an invalid character (not a number or operator), the expression is invalid
            std::cerr << "Invalid expression: invalid character " << str[i] << std::endl;
            return false;
        }
    }
    // The expression is valid if only one result remains on the stack
    return stack.size() == 1;
}

void RPN::calc(const std::string &str) {
    // First, check if the expression is valid
    if (!excheck(str))
    {
        std::cerr << "Invalid expression" << std::endl;
        return;
    }

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
    }

    // At the end, print the result which should be the only value left in the stack
    if (!stack.empty()) {
        std::cout << "Result: " << stack.top() << std::endl;
    }
}
