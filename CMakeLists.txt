cmake_minimum_required(VERSION 2.6)
project(chatsystem)

add_executable(chatsystem Chat_System/main.cpp)
include_directories(/usr/include/mysql/)
target_link_libraries(chatsystem mariadb)
install(TARGETS chatsystem RUNTIME DESTINATION bin)
