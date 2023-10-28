#include "printLine.h"

#include <string>
#include <fstream>
#include <iostream>

/*
 * @param file - input file stream
 * @param pattern - search pattern
 */

namespace readline {

    void readLine(std::ifstream &file, const std::string &pattern) {
        std::string line;
        unsigned int countLine = 0;
        unsigned int countPattern = 0;

        while (std::getline(file, line)) {
            countLine++;
            printline::printLine(line, pattern, countLine, countPattern);
        }

        if (countPattern) {
            std::cout << "Pattern find: " << countPattern << " times" << std::endl;
        } else {
            std::cout << "Pattern: " << '[' << pattern << ']' << " not find in file" << std::endl;
        }
    }

}