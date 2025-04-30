#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
public:
    int calculateResult(const std::string&);
public:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();
private:
    bool isDigitToken(const std::string& ) const;
    bool isOperator(const std::string& ) const;
    int applyOperator(int, int, const std::string&) const ;
private:
	std::stack<int> numbers;
};

#endif