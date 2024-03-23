/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:02:09 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 19:18:32 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

std::string generateRandomWord()
{
    static const char* words[] = {
        "apple", "banana", "cherry", "date", "elderberry",
        "fig", "grape", "honeydew", "kiwi", "lemon",
        "mango", "nectarine", "orange", "papaya", "quince",
        "raspberry", "strawberry", "tangerine", "ugli", "vanilla",
        "watermelon", "xigua", "yam", "zucchini",
        "acorn", "blueberry", "coconut", "dragonfruit", "endive",
        "flax", "guava", "hazelnut", "iceberg", "jalapeno",
        "kale", "lychee", "mulberry", "nutmeg", "olive",
        "parsley", "quinoa", "rosemary", "sage", "thyme",
        "unagi", "vinegar", "walnut", "xanthan", "yucca",
        "zest", "artichoke", "broccoli", "cabbage", "dill",
        "eggplant", "fennel", "garlic", "horseradish", "indigo",
        "jicama", "kohlrabi", "lettuce", "mustard", "nectar",
        "oregano", "pomegranate", "quail", "rutabaga", "spinach",
        "turmeric", "umami", "verbena", "wasabi", "xanthium",
        "yarrow", "ziti"
    };
    size_t wordCount = sizeof(words) / sizeof(words[0]);
    size_t index = rand() % wordCount;
    return words[index];
}



void createRandomFile(const std::string& filename, size_t lineCount, size_t maxWordsPerLine, const std::string& s1)
{
    std::ofstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: Could not create file: " << filename << std::endl;
        return;
    }
    for (size_t i = 0; i < lineCount; ++i)
    {
        std::string line;
        size_t wordsInLine = rand() % maxWordsPerLine + 1;

        for (size_t j = 0; j < wordsInLine; ++j)
        {
            if (!line.empty())
                line += " "; 
            line += generateRandomWord();
            if (rand() % 4 == 0)
            {
                if (!line.empty() && line.back() != ' ')
                    line += " ";
                line += s1;
                if (j + 1 < wordsInLine)
                    line += " ";
            }
        }
        file << line << "\n";
    }
}


bool run_string_replace(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::string command = "./mr_replace \"" + filename + "\" \"" + s1 + "\" \"" + s2 + "\"";
    std::cout << "\033[35m" << "Running command: " << command  << "\033[0m" << std::endl;
    return system(command.c_str()) == 0;
}


int countOccurrences(const std::string& str, const std::string& sub) {
    int count = 0;
    std::size_t pos = 0;
    while ((pos = str.find(sub, pos)) != std::string::npos) {
        ++count;
        pos += sub.length();
    }
    return count;
}

bool checkOutputFile(const std::string& modifiedFilename, const std::string& s1, const std::string& s2)
{
    std::string originalFilename = modifiedFilename.substr(0, modifiedFilename.find(".replace"));
    std::ifstream originalFile(originalFilename.c_str()), modifiedFile(modifiedFilename.c_str());

    if (!originalFile || !modifiedFile) {
        std::cerr << "Error: Could not open one of the files." << std::endl;
        return false;
    }

    std::string origLine, modLine;
    while (std::getline(originalFile, origLine) && std::getline(modifiedFile, modLine))
    {
        std::string replacedLine;
        std::size_t startPos = 0;
        while (true) {
            std::size_t pos = origLine.find(s1, startPos);
            if (pos != std::string::npos) {
                replacedLine.append(origLine, startPos, pos - startPos);
                replacedLine.append(s2);
                startPos = pos + s1.length();
            } else {
                replacedLine.append(origLine, startPos);
                break;
            }
        }
        if (replacedLine != modLine) {
            std::cerr << "Mismatch found:" << std::endl;
            std::cerr << "Original line: " << origLine << std::endl;
            std::cerr << "Expected line: " << replacedLine << std::endl;
            std::cerr << "Actual line: " << modLine << std::endl;
            return false;
        }
    }

    return true;
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    const size_t testFileCount = 30;
    const size_t maxWordsPerLine = 20;
    const size_t lineCount = 20;
    size_t       passedTests = 0;

    for (size_t i = 0; i < testFileCount; ++i) {
        std::string s1 = generateRandomWord();
        std::string filename = "test_" + std::to_string(i) + ".txt";
        createRandomFile(filename, lineCount, maxWordsPerLine, s1);

        std::string s2 = generateRandomWord();

        if (!run_string_replace(filename, s1, s2)) {
            std::cerr << "String replacement failed for file: " << filename << std::endl;
            continue;
        }

        if (!checkOutputFile(filename + ".replace", s1, s2))
            std::cerr << "Output file check failed for file: " << filename << std::endl;
        else
        {
            std::cout << "\033[32m" << "Test passed for file: " << filename << "\033[0m" << " Replaced all occurences of " + s1 + " to --> " + s2 << std::endl;
            passedTests++;
        }
    }
    if (passedTests == testFileCount)
        std::cout << "\033[1;32m\n\n\tAll tests passed!\n\n\033[0m\n";
    else
        std::cout << "\033[1;31m\n\n\tSome tests failed. Check the errors above.\033[0m\n";
    
    std::cout << "\033[33m\t\tYou can modify the file sizes & line counts and everything from the main.cpp .\033[0m\n";
    std::cout << "\033[1;33m\t\tReminder: Test escape sequences separately to ensure correct functionality !!.\033[0m\n\n\n";
    return 0;
}
