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

#include "server.hpp"

void Server::start(){//start the system
        try {//start the system on multiple threads
            std::cout << "Initializing the system, Welcome.\n";
            Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
            endpoint = std::make_shared<Pistache::Http::Endpoint>(addr);
            
            auto opts = Pistache::Http::Endpoint::options().threads(4).
            flags(Pistache::Tcp::Options::InstallSignalHandler | Pistache::Tcp::Options::ReuseAddr);
            
            endpoint->init(opts);
            setRoutes();
            endpoint->setHandler(router.handler());
            endpoint->serveThreaded();
            
            console();//call console
        }        catch (std::runtime_error &e) {
            std::cerr << "Error Found! : \n";
            std::cerr << e.what();
        }
    }

void Server::stop() {//shutdown
        endpoint->shutdown();
        std::cout << "Run Halted!";
    }

void Server::console(){//console should shut down when it detects HALT
    std::string command;
    std::cout << "Console: ";
    std::cin >> command;
    
    if(command == "HALT"){
        stop();
    }else{
        std::cerr << "Err: Wrong Command!\nConsole: ";
        std::cin >> command;
    }
}

void Server::setRoutes() {//routes
        Pistache::Rest::Routes::Post(router, "status", Pistache::Rest::Routes::bind(&Server::status, this));
    }

void Server::status(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response){
    nameValue body;
    getValues(request.body(),body);
    
    response.send(Pistache::Http::Code::Accepted, "{status, Online}" ,MIME(Application, Json));
}

//gets the names of a values of a request body
void getValues(const std::string& body, nameValue& container){
    //"[a-zA-Z1-9]*" find the name
    //^(?!Content-)[a-zA-Z1-9]* find the value
    std::string namePattern("\"[a-zA-Z1-9]*\"");
    std::string valuePattern("^(?!Content-)[a-zA-Z1-9]*");
    
    std::regex nameRegex(namePattern, std::regex::icase);
    std::regex valueRegex(valuePattern, std::regex::icase);
    
    //iterate over the body using sregex interator and put the names and values
    //into a vector
    std::vector<std::string> names;
    for(std::sregex_iterator nameIter(body.cbegin(), body.cend(), nameRegex), endIt; nameIter != endIt; ++nameIter){
        names.push_back(nameIter->str());
    }
    
    std::vector<std::string> values;
    for(std::sregex_iterator valueIter(body.cbegin(), body.cend(), valueRegex), endIt; valueIter != endIt; ++valueIter){
        values.push_back(valueIter->str());
    }
    
    //iterate over both containers and make pairs from the name and value
    auto valueIter = values.begin();
    for(auto nameIter = names.cbegin(); nameIter != names.cend(); nameIter++){
        container.push_back(std::make_pair(*nameIter, *valueIter));
        valueIter++;
    }
}
