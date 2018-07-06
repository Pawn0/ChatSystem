#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <chrono>
#include "connection.hpp"
#include "../Utils/encryption.hpp"
#include "../Utils/user.hpp"
#include "../Utils/message.hpp"

class Client {
public:
    //create a new client
    Client();

    //client operational loop
    int client();
    //register a new user
    void registerUser();

    //login
    bool logIn();

    //logout
    bool logOut();

    //switch a channel, this may throw false if the channel switch was not sucessful
    bool switchChannel();

    //get the messages from the channel we are in
    bool getMessages();


    bool sendMessage ( Message & message );

    //get a list of channels
    bool getChannels();

    //menu for the client
    int clientMenu();

    void displayMessages();
private:
    //the vector that lists the channels
    std::vector < std::pair < int, std::string > >channels;

    //vector that holds the messages
    std::vector < Message > messages;

    //variables to hold the username
    //and the current channel
    int channelID;
    std::string currentChannel;
    Connection con;
    User user;
};

#endif				/* CLIENT */
