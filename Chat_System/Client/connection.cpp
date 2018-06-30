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

#include "connection.hpp"

//for proper sending of a user we need to unpack the data


/*
 * when we send our public key,
 * we will get a public key back
*/
bool Connection::sendPublicKey()
{
    try {
	sf::Packet publicKey;
	std::string getLineStorage;
	std::string keyData;
	boost::filesystem::create_directories("../keyFolder/" + host);

	//load in the public key as a string
	std::ifstream localPublicKey("../keyFolder/publicKey",
				     std::ifstream::in);
	while (getline(localPublicKey, getLineStorage)) {
	    keyData.append(getLineStorage);
	}
    }
    catch(std::exception & e) {
	std::cout << e.what() << std::endl;
	return false;
    }
    return true;
}

void Connection::setHost()
{
    std::string getlineStorage;

    //if the file for configuration exists, read it
    if (boost::filesystem::exists("../config.txt")) {
	std::ifstream hostsFile("../config.txt", std::ifstream::in);

	//grab the first line and find the host string
	getline(hostsFile, getlineStorage);
	std::size_t location;
	location = getlineStorage.find(":");
	host = getlineStorage.substr(location + 1);
	std::cout << "Host: " << host << std::endl;

    } else {			//otherwise we need them to enter the data
	std::cout << "Please enter the Host: ";
	std::cin >> this->host;

	//make an outstream to the config file which doesnt exist yet
	std::ofstream configFile("../config.txt");

	//write the data
	configFile << "host:" + host << std::endl;
	std::cout << "Saved Host!" << std::endl;
    }
}

bool Connection::disconnect()
{
    if(token != "")
        return send("exit", token);
    else{
        std::cerr << "No token available" << std::endl;
        return false;
    }
}

bool Connection::connect()
{
    //test to see if the server is up
    return send("statusUp", "");
}

bool Connection::send(const std::string& command, const std::string& data)
{
    sf::Http http(host);

    //create a request to the server
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Post);
    request.setUri("/main.html");
    request.setHttpVersion(1, 1);	// HTTP 1.1
    request.setField("Content-Type", "application/x-www-form-urlencoded");

    std::string packet;
    std::ostringstream ostringstreamData (packet);
    ostringstreamData << "command=" << command << data;
    request.setBody(ostringstreamData.str());

    ///send that request to the server
    sf::Http::Response response = http.sendRequest(request);

    if (response.getStatus() == sf::Http::Response::Ok) {
	//we were able to connect
	connectionResult = response.getBody();
    serverResponse(connectionResult);
	return true;
    } else {
        //connection failed
        std::cerr <<
	    "Connection Failed! Server not responding try again later!" <<
	    std::endl;
        return false;
	
    }
}

//unpack the user data into a format that we can send over
bool Connection::send(const std::string& command, User& user)
{   std::string data;
    std::ostringstream outstream(data);
    user.loginData = encryption.encrypt(user.loginData);
    std::cout << "Sent User!" << std::endl;
    outstream << "email=" << user.email << "&username=" << user.username << "&login=" <<user.loginData;
    return send(command, outstream.str());
}


void Connection::serverResponse(const std::string& reply)
{
    
}
