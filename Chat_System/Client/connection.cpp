/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  pawn <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "connection.h"

//for proper sending of a user we need to unpack the data

Connection::Connection(Encryption& encrypt):encryption(encrypt){
    
}

bool Connection::connect() {
    sf::Socket::Status status = server.connect(host, port);
    
    if(status != sf::Socket::Done){
        switch(status){
            case sf::Socket::NotReady:
                std::cout << "Error! Socket not ready!." << std::endl;
                break;
            case sf::Socket::Partial:
                std::cout << "Error! Partial Send." << std::endl;
                break;
            case sf::Socket::Disconnected:
                std::cout << "Error! Socket Disconnected." << std::endl;
                break;
            case sf::Socket::Error:
                std::cout << "Error! Generic Error." << std::endl;
                break;
        }
        return false;
    }else{
        //handle the key exchange here
         //save the keys into the system
        sendPublicKey();
        return true;
    }
}

bool Connection::disconnect() {

}

bool Connection::send ( const User& user ) {
    if(connect()){
        
    }
}

bool Connection::send (const sf::String username,const sf::String password ) {
    //if we can connect, send the data over to the server
    if(connect()){
        sf::Packet packet;
        std::cout << "sending data to server[ " << "host: " << host << " port: " << port << "]"<<std::endl;
        std::cout << "Client sent-> username: " << username.toAnsiString() << " password: " << password.toAnsiString() << std::endl;
        packet << username << password;
        server.send(packet);
        return true;
    }else{
        //sending failed
        return false;
    }
}

bool Connection::send ( Message& message ) {
}

bool Connection::send ( sf::String command ) {
}

void Connection::unpack ( const User& user ) {
}

void Connection::unpack ( const Message& message ) {
}

/*
 * when we send our public key,
 * we will get a public key back
*/
void Connection::sendPublicKey(){
    sf::Packet publicKey;
    std::string getLineStorage;
    std::string keyData;
    boost::filesystem::create_directories ( "../keyFolder/" + host);
    
    //load in the public key as a string
    std::ifstream localPublicKey    ("../keyFolder/publicKey", std::ifstream::in);
    while(getline(localPublicKey, getLineStorage)){
        keyData.append(getLineStorage);
    }
}

bool Connection::setHost(){
    std::string getlineStorage;
    
    //if the file for configuration exists, read it
    if(boost::filesystem::exists ( "../config.txt" )){
        std::ifstream hostsFile("../config.txt", std::ifstream::in);
        
        //grab the first line and find the host string
        getline(hostsFile,getlineStorage);
        std::size_t location;
        location = getlineStorage.find(":");
        host = getlineStorage.substr(location + 1);
        std::cout << "Host: " << host << std::endl;
        
        //get the next line and grab the port
        getline(hostsFile,getlineStorage);
        location = getlineStorage.find(":");
        port =  boost::lexical_cast<int>(getlineStorage.substr(location + 1));
        std::cout << "Port: " << port << std::endl;
        
    }else{//otherwise we need them to enter the data
        std::cout << "Please enter the Host: ";
        std::cin >> this->host; 
        std::cout << "Please enter the Port: ";
        std::cin >> this->port;
        
        //make an outstream to the config file which doesnt exist yet
        std::ofstream configFile("../config.txt");
        
        //write the data
        configFile << "host:" + host << std::endl;
        configFile << "port:" + std::to_string(port) << std::endl;
        std::cout << "Saved Host and Port!" << std::endl;
    }
}
