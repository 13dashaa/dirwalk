cmake_minimum_required(VERSION 3.10)
project(dirwalk C) 

set(CMAKE_C_STANDARD 99)

# относительные пути к исходным файлам
add_executable(dirwalk
    src/main.c
    src/walk_directory.c
    src/print_entries.c
    src/compare_entries.c
)


target_include_directories(dirwalk PRIVATE include)
