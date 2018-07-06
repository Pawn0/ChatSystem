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

#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <string>
#include <chrono>
/**
 * @todo write docs
 */
class Message {
public:
    /**
     * Default constructor
     */
    Message ( const int &channelID, const std::string & message );
    const int &getChannelID();
    void setChannelID ( const int &chanID );

    const std::string & getMessage();
    void setMessage ( const std::string & message );

    const std::string & getTime();

private:
    int channelID;
    std::string message;
    std::string time;
    const std::string timeNow();
};

const std::string generateTime();

#endif				// MESSAGE_H
