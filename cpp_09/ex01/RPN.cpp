#include "RPN.hpp"
#include <cctype>
#include <exception>
#include <string>
#include <iostream>

/*----------------- CLASS IMPLEMENTATION -----------------*/

RPN::RPN() = default;

RPN::RPN(const RPN &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(RPN const &rhs)
{
    (void) rhs;
    return (*this);
}

RPN::~RPN() = default;

/* ------------------------------- METHODS ------------------------------- */

void RPN::runRPN(std::string &input)
{
    try
    {
        handleRPN(input);
        printResult();
    }
    catch (std::exception &e)
    {
        throw;
    }
}

void RPN::handleRPN(std::string &input)
{
    int digitCount = 0;

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        if (isdigit(*it))
        {
            _operationStack.push(*it - '0');
            digitCount++;
        }
        else if (isOperand(*it))
        {
            if (digitCount < 2)
                throw invalidOperation();
            performOperation(*it);
            digitCount--;
        }
        else if (!std::isspace(*it))
            throw invalidArgument();
    }
    if (_operationStack.size() != 1)
        throw invalidOperation();
}

void RPN::performOperation(char operation)
{
    if (_operationStack.size() < 2)
        throw invalidOperation();

    const int a = _operationStack.top();
    _operationStack.pop();
    const int b = _operationStack.top();
    _operationStack.pop();

    switch (operation)
    {
        case '+':
            _operationStack.push(b + a);
            break;
        case '-':
            _operationStack.push(b - a);
            break;
        case '*':
            _operationStack.push(b * a);
            break;
        case '/':
            if (a == 0)
                throw invalidDivision();
            _operationStack.push(b / a);
            break;
        default:
            throw invalidArgument();
    }
}

bool RPN::isOperand(char c)
{
    const std::string OPERANDS = "+-*/";
    return std::string(OPERANDS).find(c) != std::string::npos;
}

void RPN::printResult(void)
{
    if (_operationStack.size() > 1)
        throw invalidOperation();
    std::cout << _operationStack.top() << std::endl;
}

/* ------------------------------- EXCEPTIONS ------------------------------- */

const char* RPN::invalidOperation::what() const throw()
{
    return ("Error: does not respect RPN format");
}

const char* RPN::invalidArgument::what() const throw()
{
    return ("Error: invalid argument detected");
}
const char *RPN::invalidDivision::what() const throw()
{
    return ("Error cannot divide by 0");
}
