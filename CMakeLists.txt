cmake_minimum_required(VERSION 3.16)
project(git_check C)

set(CMAKE_C_STANDARD 99)

add_executable(Ex4 source/main.c source/Team.c source/Team.h source/Match.c source/Match.h source/League.c source/League.h source/sort-league.c source/sort-league.h)
