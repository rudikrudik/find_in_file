cmake_minimum_required(VERSION 3.8)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(find_in_file VERSION ${PROJECT_VERSION})

configure_file(src/version/version.h.in src/version/version.h @ONLY)


add_executable(findinfile
        src/main.cpp
        src/readLine.cpp
        src/printLine.cpp
        src/version/versionNum.cpp
        src/version/versionNum.h
        src/version/version.h
)

set_target_properties(findinfile PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    target_compile_options(findinfile PUBLIC /W4 /WX)
else()
    target_compile_options(findinfile PUBLIC -Wall -Wextra -Werror -pedantic)
endif()

install(TARGETS findinfile RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT rudik.login@gmail.com)
include(CPack)

