/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:39:42 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 17:52:12 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int replace_str_in_file(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inFile(filename.c_str());
    if (!inFile) {
         std::cerr << "Error: input file could not be opened" << std::endl;
        return - 1;
    }

    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Error: output file could not be opened" << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line << '\n';
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    replace_str_in_file(argv[1], argv[2], argv[3]);
    return 0;
}
