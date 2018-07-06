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
#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <vector>
#include <string>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <boost/lexical_cast.hpp>
#include <iomanip>
#include "../Utils/encryption.hpp"
#include "../Utils/user.hpp"
#include "../Utils/message.hpp"
/**
 * @todo write docs
 */

//connection object will store all the data related to a connection

class Connection {
public:

    //will send a username and password, must be hashed and sent properly and securely first!
    bool send ( const std::string & command, const std::string & data );

    bool send ( const std::string & command, User & user );

    bool send ( const std::string & command, Message & message );

    //send the publicKey to the server to encrypt the chat
    bool sendPublicKey();

    void setHost();

    //disconnect from the server
    bool disconnect();

private:
    //connect checks if the server is up before sending data
    bool connect();
    void serverResponse ( const std::string & reply );
    Encryption encryption;
    std::string host;
    std::string token;
    std::string connectionResult;
};

#endif				// CONNECTION_H
