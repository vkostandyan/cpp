#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>

class BitcoinExchange
{
public:
    void exchange(const std::string&);
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &);
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange &operator=(const BitcoinExchange&);
    ~BitcoinExchange();
private:
    std::map<std::string, double> data;
private:
    void process_data(const std::string&);
    std::string trim(const std::string &);
    bool isLeapYear(int);
    bool isValidDate(const std::string &);
    bool isValidValue(const std::string&);
};

#endif