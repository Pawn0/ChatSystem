#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
int main ( int argc, char **argv ){
    sf::TcpListener listener;
    sf::Packet pack;
    sf::String username;
    sf::String password;
    sf::String val3;
    sf::String val4;
    sf::String val6;
    sf::String val7;
    
    if(listener.listen(8080) != sf::Socket::Done){
        std::cout << "Server: Listening error!" << std::endl;
    }
    
    sf::TcpSocket client;
    if(listener.accept(client) != sf::Socket::Done){
        std::cout << "Server: Accepting error!" << std::endl;
    }
    
    client.receive(pack);
    if(pack >> username >> password){
        std::cout << "Server got data!" << std::endl;
        std::cout << "Server got-> username: " << username.toAnsiString() << " password: " << password.toAnsiString() << std::endl;
    }
    else{
        std::cout << "error failed to read properly" << std::endl;
        std::cout << "Server packet contains: " << pack << std::endl;
    }
    
    client.disconnect();
    return 0;
}
