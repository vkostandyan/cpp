#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &) { return *this;}

RPN::~RPN() {}

int RPN::calculateResult(const std::string& expression)
{
    std::istringstream str(expression);
    std::string token;
    while (str >> token)
    {
        if (isDigitToken(token))
            numbers.push(token[0] - '0');
        else if (isOperator(token)) 
        {
            if (numbers.size() < 2) 
                throw std::runtime_error("Invalid expression: not enough operands");

            int b = numbers.top(); 
            numbers.pop();
            int a = numbers.top(); 
            numbers.pop();
            int result = applyOperator(a, b, token);
            numbers.push(result);
        } 
        else 
            throw std::runtime_error("Invalid token: " + token);
    }
    if (numbers.size() != 1) 
        throw std::runtime_error("Invalid expression: leftover operands");
    return numbers.top();
}

bool RPN::isDigitToken(const std::string& str) const 
{
    return str.length() == 1 && std::isdigit(str[0]);
}

bool RPN::isOperator(const std::string& op) const
{
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int RPN::applyOperator(int a, int b, const std::string& op) const 
{
    if (op == "+") 
        return a + b;
    if (op == "-") 
        return a - b;
    if (op == "*") 
        return a * b;
    if (op == "/") 
    {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator: " + op);
}