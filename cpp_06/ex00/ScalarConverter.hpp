
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <stdexcept>
#include <limits>

#define RED "\033[31m"
#define DEFAULT "\033[0m"

class ScalarConverter
{
private:
    const std::string _string;
	ScalarConverter();
	~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
	static void convert(const std::string &input);

};
