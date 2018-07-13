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

#include "client.hpp"
//client is called when we create client object
Client::Client() {
    std::cout << "Chat System Started" << std::endl;
    con.setHost();
}

int Client::client() {
    //this shows the client menu
    //which will be replaced with an actual gui
    while ( clientMenu() != 4 ) {
        std::cout << "Loop still going!"<< std::endl;
    }
    return 0;
}


bool Client::registerUser() {
    std::string username;
    //prompt for the user information
    //then call a function to send it to the server
    std::cout << "Please enter your username: ";
    std::cin >> username;
    user.setUsername ( username );

    std::cout << "Please enter your email: ";
    std::string email;
    std::cin >> email;
    user.setEmail ( email );

    std::string password;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    std::string loginData = username + ":" + password;

    //create the user object
    user.setLoginData ( loginData );
    con.send ( "register", user );
}

bool Client::logIn() {
    std::string username;
    std::string password;
    std::cout << "Please enter your username: ";
    std::cin >> username;

    std::cout << "Please enter your password: ";
    std::cin >> password;

    std::string loginData = username + ":" + password;

    user.setUsername ( username );
    user.setLoginData ( loginData );
    //encrypt the data and rebind it
    return con.send ( "login", user );
}

bool Client::logOut() {
    //send a command to the server that we are logging logOut
    //and finally disconnect
    return con.disconnect();
}

bool Client::switchChannel() {
    //display the current channels
    getChannels();

    //then show the channels to the user so they canmake a choice
    std::cout << "Please select channel by ID." << std::endl;
    std::cout << "Availble channels: " << std::endl;
    std::cout << "ID:     Name:" << std::endl;
    for ( auto i = channels.cbegin(); i != channels.cend(); ++i ) {
        std::cout << i->first << i->second << std::endl;
    }

    std::cout << "Selection: ";
    std::cin >> channelID;

    //send data to the serverto get the messages for that channel
    return getMessages();
}

bool Client::getMessages() {
    return con.send ( "getMsg", std::to_string ( channelID ) );
}

bool Client::sendMessage ( Message & message ) {
    if(message.getMessage() == "")
        return false;
    else
        return con.send ( "msg", message );
}

bool Client::getChannels() {
    return con.send ( "getChan", "all" );
}

int Client::clientMenu() {
    std::cout << "Please select an option." << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register " << std::endl;
    std::cout << "3. Set Host " << std::endl;
    std::cout << "4. exit " << std::endl;
    std::cout << "Selection: ";
    int opt;
    std::cin >> opt;

    switch ( opt ) {
    case 1:			//login
        logIn();
        break;
    case 2:			//register a new user
        registerUser();
        break;
    case 3:			//set the host of the server
        con.setHost();
        break;
    case 4:
        opt = 4;
        con.disconnect();
        break;
    default:
        break;
    }
    return opt;
}

void Client::displayMessages() {
    std::system ( "clear" );

}
