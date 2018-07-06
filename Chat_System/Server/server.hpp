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

#ifndef SERVER_HPP
#define SERVER_HPP

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>
#include <pistache/net.h>
#include "../Utils/encryption.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <memory>
#include <fstream>
#include <regex>

/**
 * @todo write docs
 */
typedef std::vector<std::pair<std::string, std::string>> nameValue;
class Server {

    
public:
    void start(); //start function, actually calls console
    void stop(); //stops the system gracefully
    
private:
    void setRoutes(); //routes

    //route for checking if the server is up
    void status(const Pistache::Rest::Request &request,
            Pistache::Http::ResponseWriter response);

    
    void console(); //console is called automatically
    
    
    std::shared_ptr<Pistache::Http::Endpoint> endpoint;
    Pistache::Rest::Router router;
    Encryption encryption;
    
    
};

void getValues(const std::string& body, nameValue& container);


#endif				// SERVER_H
