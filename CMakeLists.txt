cmake_minimum_required(VERSION 4.0)
project(trading_system)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/g++-15")

add_custom_target(assembly
        COMMAND g++-15 -S ${CMAKE_SOURCE_DIR}/main.cpp -o ${CMAKE_BINARY_DIR}/main.s
)

add_executable(trading_system main.cpp
        order_book_entry.cpp
        merkel_main.cpp
        csv_reader.cpp
)

add_executable(csv_parser csv_parser.cpp)

