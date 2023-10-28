#include <string>
#include <iostream>

/*
 *
 * @param line - input line from file
 * @param pattern - find pattern in line
 * @return countLine
 * @return countPattern - how many times pattern find
 */

static std::string red = "\033[91m";
static std::string green = "\033[32m";
static std::string standard = "\033[0m";

namespace printline {

    void printLine(const std::string &line, const std::string &pattern,
                   unsigned int &countLine, unsigned int &countPattern) {

        unsigned int start = 0;
        unsigned int lenPattern = pattern.length();
        unsigned int position = 0;

        while (line.find(pattern, position) != std::string::npos) {
            position = line.find(pattern, position);
            countPattern++;

            if (!start) {
                std::cout << green << countLine << ":  " << standard;
            }

            std::cout << line.substr(start, position - start);
            std::cout << red << line.substr(position, lenPattern) << standard;

            position += lenPattern;
            start = position;
        }

        if (position) {
            std::cout << line.substr(position) << std::endl;
        }
    }
}