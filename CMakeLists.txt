cmake_minimum_required(VERSION 3.8)

project(find_in_file)

add_executable(find_in_file
        main.cpp
        readLine.cpp
        printLine.cpp
        )

set_target_properties(find_in_file PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    target_compile_options(find_in_file PUBLIC /W4 /WX)
else()
    target_compile_options(find_in_file PUBLIC -Wall -Wextra -Werror -pedantic)
endif()


