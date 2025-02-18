cmake_minimum_required(VERSION 3.10)
project(dirwalk C) 

#стандарт c11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#каталоги для Release и Debug
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

#флаги для Debug
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -ggdb -std=c11 -pedantic -W -Wall -Wextra")

#флаги для Release
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=c11 -pedantic -W -Wall -Wextra -Werror")

#конфигурация по умолчанию
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


# относительные пути к исходным файлам
add_executable(dirwalk
    src/main.c
    src/walk_directory.c
    src/print_entries.c
    src/compare_entries.c
)


target_include_directories(dirwalk PRIVATE include)
