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

bool Connection::connect(const std::string& host, short unsigned int& port) {
    sf::Packet commandPacket;
    sf::Packet dataPacket;
    sf::String data;
    sf::Socket::Status status = server.connect(host, port);
    
    //which we save and then load into the system using encrpytion
    
    
    if(status != sf::Socket::Done){
        
    }
}

bool Connection::disconnect() {

}

bool Connection::send ( const User& user ) {
}

bool Connection::send ( sf::String& username, sf::String& password ) {
    connect("localhost", 8080);
    sf::Packet user;
    user << "login" << username << password;
    server.send(user);
}

bool Connection::send ( Message message ) {
}

bool Connection::send ( sf::String command ) {
}

void Connection::unpack ( const User& user ) {
}

void Connection::unpack ( const Message& message ) {
}

bool Connection::sendPublicKey(const std::string& username, const std::string&password, CryptoPP::RSA::PublicKey& publicKey){
}

bool Connection::setHost(const std::string& host, unsigned short port){
    this->host = host;
    this->port = port;
}
