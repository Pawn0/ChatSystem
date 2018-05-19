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

#include "client.h"

//client is called when we create client object
Client::Client() {
    switch ( welcomeMsg() ) {
    case 1:
        logIn();
        break;
    case 2:
        registerUser();
        break;
    default:
        welcomeMsg();
    }
}

bool Client::registerUser() {
    //prompt for the user information
    //then call a function to send it to the server
    std::cout << "Please enter your username: ";
    std::string username;
    std::cin >> username;

    std::cout << "Please enter your email: ";
    std::string email;
    std::cin >> email;

    std::cout << "Please enter your password: ";
    std::string password;
    std::cin >> password;


    //create the user object
    User user ( username, email, password );

    //try to open a connection to the server to post the data
    try {


    } catch ( std::exception &e ) {
        std::cout << e.what() << std::endl;
    }
}//end registerUser

bool Client::logIn() {
    std::cout << "Please enter your username: ";
    std::cin >> username;


}

bool Client::logOut() {

}

bool Client::switchChannel() {
}

const std::string& Client::getChannel() {
}

bool Client::sendMessage ( Message msg ) {
}

bool Client::getMessages() {
}

bool Client::getChannels() {

}

bool Client::send ( const std::string& command ) {
}

int Client::welcomeMsg() {
    int option = 0;
    std::cout << "Welcome to our humble chat system." << std::endl;
    std::cout << "Please select an option." << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register " << std::endl;
    std::cin >> option;
    return option;
}

