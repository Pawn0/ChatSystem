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
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Network.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include "user.h"
#include "message.h"
/**
 * @todo write docs
 */

//connection object will store all the data related to a connection
class Connection{
public:
    Connection();
private:
    std::vector<std::vector<Message>> messageChannels;
    void unpackUser();
    sf::TcpSocket socket;
    sf::Socket::Status status;
};

#endif // CONNECTION_H
