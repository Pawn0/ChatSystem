#ifndef _CLIENT_
#define _CLIENT_

#include <vector>
#include <string>
#include <iostream>
#include "connection.h"
#include "user.h"
#include "message.h"

class Client
{
public:
  //create a new client
  Client ();

  //register a new user
  bool registerUser ();

  //login
  bool logIn ();

  //logout
  bool logOut ();

  //set the server to connect to
  bool setServer (const std::string serverIp);

  //switch a channel, this may throw false if the channel switch was not sucessful
  bool switchChannel ();

  //get the channel, this is returned as a string
  const std::string & getChannel ();

  //send a message to the server, this is a chat message
  bool sendMessage (Message msg);

  //get the messages from the channel we are in
  bool getMessages ();

  //get a list of channels
  bool getChannels ();
private:
  //used to send commands to the server
    bool send (const std::string & command);

  //display the welcoming message
  int welcomeMsg ();

  //contains the vector that lists the channels
    std::vector < std::string > channels;

  //represents the sfml connection
  Connection con;

  //variables to hold the username
  //and the current channel
  int userID;
  int channelID;
    std::string username;
    std::string password;
    std::string currentChannel;
    std::vector < std::vector < Message >> messageChannels;
};

#endif /* CLIENT */
