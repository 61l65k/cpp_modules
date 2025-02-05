#pragma once


#include <exception>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

class BitcoinExchange
{
private:
	std::map<std::string , float> _dataBase;

	void validateDate(std::string date);
   	void validateValue(std::string value);
   	void printFormatedLine(std::string date, float value);
  	void csvToMap(void);


public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	void startExchange(std::string &inputPath);

	class InvalidDateException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class InvalidFilePath : public std::exception
	{
		virtual const char *what() const throw();
	};
	class NegativeNumberException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class toLargeException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class BadInputException : public std::exception
    {
    private:
        std::string message;
    public:
        BadInputException(const std::string &input);
        virtual const char *what() const throw();
    };
};
