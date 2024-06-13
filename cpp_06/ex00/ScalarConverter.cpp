#include "ScalarConverter.hpp"

static double stringToDouble(const std::string &input)
{
    std::string modifiedInput = input;
    if (!modifiedInput.empty() && modifiedInput[modifiedInput.size() - 1] == 'f')
        modifiedInput.erase(modifiedInput.size() - 1);

    std::istringstream stream(modifiedInput);
    double doubleValue;
    stream >> doubleValue;
    if (stream.fail() || !stream.eof())
        throw std::runtime_error(ERR_DBL);

    return doubleValue;
}

static void convertChar(double d)
{
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible (out of char range)\n";
    else 
    {
        const char c = static_cast<char>(d);
        if (!isprint(c))
            std::cout << "char: impossible (non-printable character)\n";
        else
            std::cout << "char: '" << c << "'\n";
    }
}

static void convertInt(double d)
{
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible (out of int range)\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
}

static void convertFloat(double d)
{
    std::cout << std::fixed << std::setprecision(1)
              << "float: " << static_cast<float>(d) << "f\n";
}

static void convertDouble(double d)
{
    std::cout << "double: " << d << std::endl;
}

static bool handlePseudoLiterals(const std::string &input)
{
    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: nanf\n"
                  << "double: nan" << std::endl;
        return true;
    }
    else if (input == "-inf" || input == "+inf" || input == "-inff" || input == "+inff")
    {
        const std::string doubleValue = input.substr(0, input.size() - (input[input.size() - 1] == 'f' ? 1 : 0));
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: " << input << "\n"
                  << "double: " << doubleValue << std::endl;
        return true;
    }
    return false;
}

static bool handleSingleChar(const std::string &input)
{
    if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0]))
    {
        char c = input[0];
        std::cout << "char: '" << c << "'\n"
                  << "int: " << static_cast<int>(c) << "\n"
                  << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n"
                  << "double: " << static_cast<double>(c) << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string &input)
{
    try
    {
        if (handlePseudoLiterals(input))
            return;

        if (handleSingleChar(input))
            return;

        double d = stringToDouble(input);
        if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
            throw std::runtime_error("Number out of range for double conversion");

        convertChar(d);
        convertInt(d);
        convertFloat(d);
        convertDouble(d);
    }
    catch (const std::runtime_error &e)
    {
        throw e;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}
