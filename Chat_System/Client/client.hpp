#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vector>
#include <string>
#include <iostream>
#include <SFML/System.hpp>
#include "connection.hpp"
#include "encryption.hpp"
#include "user.hpp"

class Client {
  public:
    //create a new client
    Client();

    //client operational loop
    void client();
    //register a new user
    void registerUser();

    //login
    bool logIn();

    //logout
    bool logOut();

    //switch a channel, this may throw false if the channel switch was not sucessful
    bool switchChannel();

    //get the channel, this is returned as a string constant
    //meaning if they 
    const std::string & getChannel();

    //get the messages from the channel we are in
    bool getMessages(const int& channelID);


    bool sendMessage(const std::string & message);

    //get a list of channels
    bool getChannels();

    //menu for the client
    int clientMenu();
  private:
    //the vector that lists the channels
     std::vector < std::string > channels;

    //vector that holds the messages
     std::vector < std::string > messages;

    //variables to hold the username
    //and the current channel
    int userID;
    int channelID;
     std::string currentChannel;
    Connection con;
    User user;
};

#endif				/* CLIENT */
