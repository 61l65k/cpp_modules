#include "BitcoinExchange.hpp"

/* ------------------------------- CONSTRUCTORS ------------------------------- */

BitcoinExchange::BitcoinExchange()
{
    try
    {
        this->csvToMap();
    }
    catch (std::exception &e)
    {
        throw InvalidFilePath();
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    this->_dataBase = src._dataBase;
}

BitcoinExchange::~BitcoinExchange()
{
	_dataBase.clear();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    (void )rhs;
    return *this;
}

/* ------------------------------- METHODS ------------------------------- */

void BitcoinExchange::csvToMap()
{
    std::ifstream dbFile;
    std::string date = "";
	std::string line = "";
	float value = 0.0;
    bool firstLine = true;
    dbFile.open("data.csv", std::ifstream::in);
    if (!dbFile.is_open())
    {
		 throw InvalidFilePath();
	}
    while (!dbFile.eof())
    {
        getline(dbFile, line);
        if (firstLine == true)
        {
            if (line != "date,exchange_rate")
                throw BadInputException(line);
			firstLine = false;
        }
        else
		{
			date = line.substr(0, line.find(","));
			value = std::atof(line.substr(line.find(",")+1 ,line.length()).c_str());
			_dataBase.insert(std::make_pair(date, value));
		}
    }
	dbFile.close();
}

void BitcoinExchange::startExchange(std::string &path)
{
    std::ifstream inFile;
    std::string line = "";
    std::string date = "";
    bool firstLine = true;
    std::string  value = "";
    inFile.open(path.c_str(), std::ifstream::in);
    if (!inFile.is_open())
        throw InvalidFilePath();
    while (!inFile.eof())
    {
        getline(inFile, line);
        if (firstLine == true)
        {
            if (line != "date | value")
                throw BadInputException(line);
            firstLine = false;
        }
        else
        {
            if (line.find("|") == line.npos || line.empty() || line.find("|") != 11)
            {
                std::cout << "Error: invalid format" << std::endl;
            }
            else
            {
                if (line[0] != '\n')
                {
                    date = line.substr(0, line.find("|") -1);
                    value = line.substr(line.find("|") + 2, line.length());
                    try
                    {
                        BitcoinExchange::checkDate(date);
                        BitcoinExchange::checkValue(value);
                        BitcoinExchange::printFormatedLine(date, std::atof(value.c_str()));
                    }
                    catch(std::exception &e)
                    {
                        std::cout << e.what()  << std::endl; ;
                    }
                }
            }
        }
    }
    inFile.close();
}

void BitcoinExchange::checkDate(std::string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw BadInputException(date);

    const std::string yearStr = date.substr(0, 4);
    const std::string monthStr = date.substr(5, 2);
    const std::string dayStr = date.substr(8, 2);

    const int year = std::atoi(yearStr.c_str());
    const int month = std::atoi(monthStr.c_str());
    const int day = std::atoi(dayStr.c_str());

    if (year <= 0 || month <= 0 || month > 12 || day <= 0)
        throw BadInputException(date);

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
        maxDay = 29;
    }
    if (day > maxDay)
        throw BadInputException(date);
}

void BitcoinExchange::checkValue(std::string value)
{
	if (value.length() > 4)
	{
	   throw toLargeException();
	}
	const float checkValue = std::atof(value.c_str());
	if (checkValue > 1000.0)
    {
        throw toLargeException();
    }
	else if(checkValue < 0.0)
	{
	   throw NegativeNumberException();
	}
}

void BitcoinExchange::printFormatedLine(std::string date, float value)
{
    std::map<std::string, float>::iterator it = _dataBase.lower_bound(date);
    if (it == _dataBase.end())
    {
        it--;
    }
    std::cout << it->first << " => " << value << " = "<< (value * it->second) << std::endl;
}


/* ------------------------------- EXCEPTIONS ------------------------------- */

const char *BitcoinExchange::InvalidFilePath::what() const  throw()
{
    return ("Error: invalid file path or permissions");
}

const char *BitcoinExchange::toLargeException::what() const throw()
{
    return ("Error: too large number");
}
const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
    return ("Error: not a positive number");
}

BitcoinExchange::BadInputException::BadInputException(const std::string &input) 
    : message("Error: bad input => " + input) {}

const char *BitcoinExchange::BadInputException::what() const throw()
{
    return message.c_str();
}
