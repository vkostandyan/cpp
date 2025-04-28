#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printNan(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
}

void ScalarConverter::printInf(const std::string &str)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << (str[0] == '-' ? "-" : "+") << "inff" << std::endl;
	std::cout << "double: " << (str[0] == '-' ? "-" : "+") << "inf" << std::endl;
}

void ScalarConverter::printError(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

bool ScalarConverter::checkNumber(const std::string &str)
{
    if (str.empty())
        return false;

    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    if (i >= str.size())
        return false;

    bool hasDot = false;
    bool hasDigit = false;
    size_t len = str.length();
    if (str[len - 1] == 'f')
        --len;
    for (; i < len; ++i)
    {
        if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(str[i]))
            hasDigit = true;
        else
            return false;
    }
    return hasDigit;
}

void ScalarConverter::printChar(const std::string &str)
{
    char c = static_cast<char>(std::atoi(str.c_str()));
    std::cout << "char: ";
	if (c < 0)
		std::cout << "impossible" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
}

void ScalarConverter::printInt(const std::string &str)
{
    std::cout << "int: " << std::atoi(str.c_str()) << std::endl;
}

void ScalarConverter::printFloat(const std::string &str)
{
    float res = std::strtof(str.c_str(), NULL);
    std::cout << "float: " << res;
    if (res == static_cast<int>(res))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(const std::string &str)
{
	double res = std::strtod(str.c_str(), NULL);
	std::cout << "double: " << res;
	if (res == static_cast<int>(res))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    if (str == "nan" || str == "nanf")
        printNan();
    else if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff" || str == "-inf" || str == "-inff")
        printInf(str);
    else if (checkNumber(str))
    {
        printChar(str);
        printInt(str);
        printFloat(str);
		printDouble(str);
    }
    else
        printError();
}
