#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
int main ( int argc, char **argv ){
    sf::TcpListener listener;
    sf::Packet pack;
    std::string val = "";
     std::string val1 = "";
      std::string val2 = "";
    if(listener.listen(8080) != sf::Socket::Done){
        
    }
    
    sf::TcpSocket client;
    if(listener.accept(client) != sf::Socket::Done){
        
    }
    
    pack >> val >> val1 >> val2;
    
    std::cout << val1 << val2 << val2; 
    return 0;
}
