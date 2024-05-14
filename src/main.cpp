#include <iostream>
#include <fstream>
#include <string>

#include "readLine.h"
#include "version/versionNum.h"

#ifdef _WIN32
#include <Windows.h>
#endif


int main(int argc, char *argv[]) {

#ifdef _WIN32
    DWORD con_mode;
    GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &con_mode);
    con_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), con_mode);
#endif

    if(argc < 3 || argc > 3){
        if(argc == 2 && static_cast<std::string>(argv[1]) == "--version"){
            std::cout << version();
        }
        else {
            std::cout << "Usage: findinfile [PATH_TO_FILE] [FIND_PATTERN]" << std::endl;
            std::cout << "Version: findinfile --version" << std::endl;
            return 0;
        }
    }
    else {
        std::ifstream file(argv[1]);
        std::string pattern = argv[2];

        if(file.is_open()){
            readline::readLine(file, pattern);
        }
        else {
            std::cout << "Unable to open file: " << argv[1] << std::endl;
        }
    }
    return 0;
}
