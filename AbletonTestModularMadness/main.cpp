//
//  main.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 19/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "Model/Network.hpp"

// Returns false if the command is terminal
bool receive_input(Network* network) {
    std::string command;

    getline(std::cin, command);
    
    std::istringstream iss(command);

    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                           std::istream_iterator<std::string>());
    std::string type = results.at(0);
    if (type == "quit") {
        return false;
    } else if (type == "module") {
        std::string type = results.at(2);
        std::string name = results.at(1);
        network -> makeModule(name, type);
    } else if (type == "connect") {
        std::string name1 = results.at(1);
        std::string name2 = results.at(2);
        network -> makeConnection(name1, name2);
    } else if (type == "process") {
        std::string input = results.at(1);
        std::string output = "";
        network -> process(input, output);
        std::cout << output << std::endl;
    } else {
        std::cout << "Unknown input. Please try again." << std::endl;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::cout << "Welcome to Modular Madness!" << std::endl;
    
    Network* network = new Network();
    
    bool run = true;
    
    while (run) {
        run = receive_input(network);
    }
    
    delete network;
    
    return 0;
}
