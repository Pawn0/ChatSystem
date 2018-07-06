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

#include "message.hpp"

Message::Message ( const int &channelID, const std::string & message )
    :channelID ( channelID ), message ( message ), time ( timeNow() ) {
}

const int &Message::getChannelID() {
    return channelID;
}

void Message::setChannelID ( const int &chanID ) {
    channelID = chanID;
}

const std::string & Message::getMessage() {
    return message;
}


const std::string Message::timeNow() {
    return generateTime();
}

const std::string generateTime() {
    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t ( now );
    return std::ctime ( &t );
}
