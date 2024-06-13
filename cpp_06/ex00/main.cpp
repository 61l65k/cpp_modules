#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
			std::cout << "wrong nr. of arguments!" << std::endl;
			return 1;
	}
    try{
        ScalarConverter::convert(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << DEFAULT << std::endl;
    }
	return 0;
}
