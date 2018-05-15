cmake_minimum_required(VERSION 2.6)
project(chatsystem)

add_executable(chatsystem main.cpp)

install(TARGETS chatsystem RUNTIME DESTINATION bin)
