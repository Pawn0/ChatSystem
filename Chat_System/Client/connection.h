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


//this object will represent an object that is used through sfml
//to connect to a server
#ifndef CONNECTION_H
#define CONNECTION_H

#include <vector>
#include <string>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include "encryption.h"
#include "user.h"
#include "message.h"
/**
 * @todo write docs
 */

//connection object will store all the data related to a connection

class Connection
{
public:
    Connection(Encryption& encryption);
  //connect to the server, will also close connection at the end
  bool connect (const std::string& host, short unsigned int& port);

  //disconnect from the server
  bool disconnect ();
  //will send a user, which has to be unpacked first
  bool send (const User & user);

  //will send a username and password, must be hashed and sent properly and securely first!
  bool send (sf::String & username, sf::String & password);

  //will send a message to the server
  bool send (Message message);

  //will send a command, meant to be used to get data from the server
  bool send (sf::String command);
  
  //send the publicKey to the server to encrypt the chat
  bool sendPublicKey(const std::string& username, const std::string&password ,CryptoPP::RSA::PublicKey& publicKey);
  
  bool setHost(const std::string& host, short unsigned int port);
private:
  //used to unpack a user object into sf objects
  void unpack (const User & user);

  //used to unpack a message
  void unpack (const Message & message);
    Encryption& encryption;
    sf::TcpSocket server;
    std::string host;
    short unsigned int port;
    
};

#endif // CONNECTION_H
