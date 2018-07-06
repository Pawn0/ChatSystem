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

#include "user.hpp"

User::User::User() {
}

User::User ( const std::string & uname, const std::string & email )
    :username ( uname ), email ( email ) {
}

const std::string & User::getUsername() {
    return username;
}

void User::setUsername ( const std::string & uName ) {
    username = uName;
}

const int &User::getUserID() {
    return userID;
}

void User::setUserID ( const int &id ) {
    userID = id;
}

const std::string & User::getEmail() {
    return email;
}

void User::setEmail ( const std::string & email ) {
    this->email = email;
}

const std::string & User::getLoginData() {
    return loginData;
}

void User::setLoginData ( const std::string & loginData ) {
    this->loginData = loginData;
}
