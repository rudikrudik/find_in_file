#include "readLine.h"

#include <iostream>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif


int main(int argc, char *argv[]) {

#ifdef _WIN32
    DWORD con_mode;
    GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &con_mode);
    con_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), con_mode);
#endif

    if(argc < 3 || argc > 3){
        std::cout << "Usage: find_in_file [PATH_TO_FILE] [FIND_PATTERN]" << std::endl;
        return 0;
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
