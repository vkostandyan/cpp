#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
public:
    static void convert(const std::string&);
private:
    static void printNan(void);
    static void printInf(const std::string &);
    static void printChar(const std::string &);
    static void printInt(const std::string &);
    static void printFloat(const std::string &);
    static void printDouble(const std::string &);
    static void printError(void);
    static bool checkNumber(const std::string &);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();
};

#endif