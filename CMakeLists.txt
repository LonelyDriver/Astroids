cmake_minimum_required(VERSION 3.13)
project(blockwars CXX)

if(UNIX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-Wall -Wextra -pedantic -Werror)
elseif(MCVC)
add_compile_options(/W4)
endif()

find_package(Threads)

add_subdirectory(lib)

if(MSVC)
find_package(SDL2)
endif()

add_library(block_library 
    SHARED
    src/block_game.cpp)
target_include_directories(block_library PRIVATE src lib/Logging/include lib/Vector/include)
target_link_libraries(block_library vector logger SDL2 SDL2_image SDL2_ttf)

add_executable(block_wars src/examples/block_wars.cpp)
target_include_directories(block_wars PRIVATE src)
target_link_libraries(block_wars block_library)