/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:39:42 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 19:09:05 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string interpret_escape_sequences(const std::string& str) {
    std::string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\\' && i + 1 < str.length())
        {
            switch (str[i + 1]) {
                case 'n': result.push_back('\n'); break;
                case 't': result.push_back('\t'); break;
                case 'r': result.push_back('\r'); break;
                case 'v': result.push_back('\v'); break;
                case 'b': result.push_back('\b'); break;
                default: result.push_back(str[i + 1]); break;
            }
            ++i;
        }
        else
            result.push_back(str[i]);
    }
    return result;
}

void ft_replaceStrings(const std::string& fileName, const std::string& s1, const std::string& s2) {
    std::ifstream file(fileName.c_str(), std::ios::binary);
    if (!file.is_open()) {
        std::cout << "The file doesn't exist or you don't have read permissions.\n";
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    std::string replace_str = interpret_escape_sequences(s1);
    std::string new_str = interpret_escape_sequences(s2);

    size_t pos = 0;
    if (s1.empty() || s2.empty())
    {
        std::cout << "The replacement strings can't be empty.\n";
        return file.close();
    }
    if (content.empty() ) {
        std::cout << "The file is empty.\n";
        return file.close();
    }
    while ((pos = content.find(replace_str, pos)) != std::string::npos) {
        content.replace(pos, replace_str.length(), new_str);
        pos += new_str.length();
    }

    file.close();

    std::ofstream outfile((fileName + ".replace").c_str(), std::ios::binary | std::ios::trunc);
    if(outfile) {
        outfile << content;
    } else {
        std::cout << "Failed to open the output file for writing.\n";
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Invalid args: ./mr_replace <filename> <replaced_string> <new_string>\n";
        return 1;
    }

    ft_replaceStrings(argv[1], argv[2], argv[3]);
    return 0;
}
