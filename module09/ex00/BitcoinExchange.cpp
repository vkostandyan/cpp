#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;

    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &fname)
{
	this->process_data(fname);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string &s) 
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

void BitcoinExchange::process_data(const std::string &fname) 
{
    std::ifstream dict(fname.c_str());
    if (!dict.is_open())
        throw std::runtime_error("Couldn't open CSV file.");

    std::string line;
    std::getline(dict, line);

    while (std::getline(dict, line)) 
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw std::runtime_error("Invalid CSV format: missing comma.");

        std::string key = trim(line.substr(0, pos));
        std::string valStr = trim(line.substr(pos + 1));

        try
        {
            double value = std::atof(valStr.c_str());
            data.insert(std::make_pair(key, value));
        } catch (const std::exception &e) 
        {
            throw std::runtime_error("Invalid number format in CSV: " + valStr);
        }
    }
}

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	int year, month, day;
	char dash1, dash2;

	if (date.size() != 10)
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return false;   
		}
		else if (!std::isdigit(date[i]))
			return false;
	}
	std::istringstream ss(date);
	ss >> year >> dash1 >> month >> dash2 >> day;
	if (ss.fail() || !ss.eof())
		return false;
	else if (month < 1 || month > 12 || day < 1 || year == 0)
		return false;
	switch (month)
	{
	case 2:
		return (day <= (isLeapYear(year) ? 29 : 28));
	case 4:
	case 6:
	case 9:
	case 11:
		return (day <= 30);
	default:
		return (day <= 31);
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
	double num;
	std::stringstream ss(value);
	ss >> num;
	if (ss.fail() || !ss.eof())
	{
		std::cout << "Error: bad input" << std::endl;
		return false;
	}
	else if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (num > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::exchange(const std::string &fname)
{
	std::ifstream infile(fname.c_str());
	if (!infile.is_open() || infile.eof())
		throw std::runtime_error("Couldn't open input file.");
	std::string header;
	std::getline(infile, header);
	if (header != "date | value")
		throw std::runtime_error("Invalid input file.");
	std::string line;
	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, pos));
		std::string value = trim(line.substr(pos + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: invalid date format => " << date << std::endl;
			continue;
		}
		else if (!isValidValue(value))
			continue;
		else
		{
			double price = std::atof(value.c_str());
			std::map<std::string, double>::const_iterator it = this->data.lower_bound(date);
			if (it == this->data.end())
				--it;
			else if (it != this->data.begin() && it->first != date)
			{
				std::map<std::string, double>::const_iterator prevIt = it;
				--prevIt;
				--it;
				if ((date.compare(it->first) - date.compare(prevIt->first)) > 0)
					it = prevIt;
			}
			std::cout << date << " => " << price << " = " << price * it->second << std::endl;
		}
	}
}