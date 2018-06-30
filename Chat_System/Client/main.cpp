#include <iostream>
#include <thread>
#include <vector>
#include "client.hpp"

int main(int argc, char **argv)
{
    Client client;
    /*this vector will allow the software to contain a gui and a backend
       the front end will be another thread, and the backend is a thread
       more threads can be added as needed
     */

    std::vector < std::thread > actors;
    actors.push_back(std::thread(&Client::client, &client));

    //lastly we will join all the threads, if exiting
  for (std::thread & i:actors) {
	i.join();
    }
    return 0;
}
