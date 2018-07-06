#include <iostream>
#include <thread>
#include <vector>
#include "client.hpp"

int main ( int argc, char **argv ) {

    Client client;

    //components holds our system items
    std::vector < std::thread > components;

    //put our client software in its own thread
    //that way we can have a GUI thread and a client thread
    components.push_back ( std::thread ( &Client::client, &client ) );

    //lastly we will join all the threads, if exiting
    for ( std::thread & i:components ) {
        i.join();
    }
    return 0;
}
