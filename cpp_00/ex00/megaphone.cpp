#include <iostream>

static char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a' + 'A');
    return (c);
}

int main(int argc, char **argv) {
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j]; ++j)
            std::cout << ft_toupper(argv[i][j]);
    }
    std::cout << std::endl;
    return (0);
}
