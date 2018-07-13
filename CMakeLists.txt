cmake_minimum_required(VERSION 3.1)
project(chatsystem)

SET(CMAKE_CXX_FLAGS "-std=c++14")
set(CLIENT_SOURCES Chat_System/Client/main.cpp Chat_System/Client/client.hpp Chat_System/Client/client.cpp Chat_System/Client/connection.hpp Chat_System/Client/connection.cpp)

set(SERVER_SOURCES  Chat_System/Server/main.cpp Chat_System/Server/server.hpp Chat_System/Server/server.cpp Chat_System/Server/json.hpp)

set(UTIL_SOURCES Chat_System/Utils/encryption.hpp Chat_System/Utils/encryption.cpp Chat_System/Utils/message.hpp Chat_System/Utils/message.cpp Chat_System/Utils/user.hpp Chat_System/Utils/user.cpp)

add_executable(client  ${CLIENT_SOURCES} ${UTIL_SOURCES})
add_executable(server  ${SERVER_SOURCES} ${UTIL_SOURCES})
add_executable(test Chat_System/Tests/test.cpp)

include_directories(usr/include/mysql usr/include/SFML usr/include/cryptopp usr/include/Poco/Net/)

set(COMMON_LIBS  cryptopp boost_system boost_filesystem pthread PocoNet)
target_link_libraries(client ${COMMON_LIBS} )
target_link_libraries(server mariadb pistache ${COMMON_LIBS})
target_link_libraries(test gtest ${COMMON_LIBS})
install(TARGETS client server test RUNTIME DESTINATION bin)
