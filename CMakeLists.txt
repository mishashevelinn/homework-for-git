cmake_minimum_required(VERSION 3.16)
project(git_check C)

set(CMAKE_C_STANDARD 99)

add_executable(Ex4 main.c Team.c Team.h Match.c Match.h League.c League.h sort-league.c sort-league.h)
