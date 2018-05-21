cmake_minimum_required(VERSION 2.6)
project(chatsystem)

add_definitions(-std=c++17)
set(CLIENT_SOURCES Chat_System/Client/main.cpp Chat_System/Client/client.h Chat_System/Client/client.cpp Chat_System/Client/connection.h Chat_System/Client/connection.cpp Chat_System/Client/message.h Chat_System/Client/message.cpp Chat_System/Client/user.h Chat_System/Client/user.cpp Chat_System/Client/encryption.h Chat_System/Client/encryption.cpp)
set(SERVER_SOURCES  Chat_System/Server/main.cpp Chat_System/Server/user.h Chat_System/Server/user.cpp)
add_executable(client  ${CLIENT_SOURCES})
add_executable(server  ${SERVER_SOURCES})

include_directories(usr/include/mysql /usr/include/SFML /usr/include/cryptopp)
target_link_libraries(client sfml-system sfml-network cryptopp boost_system boost_filesystem)
target_link_libraries(server mariadb cryptopp)
install(TARGETS client server RUNTIME DESTINATION bin)
