cmake_minimum_required(VERSION 2.6)
project(chatsystem)

add_definitions(-std=c++11)
set(CLIENT_SOURCES Chat_System/Client/main.cpp Chat_System/Client/client.hpp Chat_System/Client/client.cpp Chat_System/Client/connection.hpp Chat_System/Client/connection.cpp Chat_System/Client/message.hpp Chat_System/Client/message.cpp Chat_System/Client/user.hpp Chat_System/Client/user.cpp Chat_System/Client/encryption.hpp Chat_System/Client/encryption.cpp)

set(SERVER_SOURCES  Chat_System/Server/main.cpp Chat_System/Client/encryption.hpp Chat_System/Client/encryption.cpp Chat_System/Server/server.hpp Chat_System/Server/server.cpp)
add_executable(client  ${CLIENT_SOURCES})
add_executable(server  ${SERVER_SOURCES})

include_directories(usr/include/mysql usr/include/SFML usr/include/cryptopp usr/include/libssh)
target_link_libraries(client sfml-system sfml-network cryptopp boost_system boost_filesystem pthread)
target_link_libraries(server mariadb cryptopp sfml-system sfml-network cryptopp boost_system boost_filesystem libpistache.a)
install(TARGETS client server RUNTIME DESTINATION bin)
