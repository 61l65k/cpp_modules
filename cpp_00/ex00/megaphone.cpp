#include <iostream>
#define NO_ARGS_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << NO_ARGS_MSG;
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char)std::toupper(argv[i][j]);
    }
    std::cout << std::endl;
    return (0);
}
