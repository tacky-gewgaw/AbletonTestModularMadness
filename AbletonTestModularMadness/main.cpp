//
//  main.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 19/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "NetworkController.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Welcome to Modular Madness!" << std::endl << "Type \"quit\" to exit." << std::endl;
    
    NetworkController* nc = new NetworkController();
    
    bool run = true;
    
    while (run) {
        std::string rawInput;
        
        getline(std::cin, rawInput);
        
        std::istringstream iss(rawInput);
        
        std::vector<std::string> commandVector((std::istream_iterator<std::string>(iss)),
                                               std::istream_iterator<std::string>());
        std::string calledFunction = commandVector.at(0);
        if (calledFunction == "quit") {
            run = false;
        } else {
            nc -> handleInput(commandVector);
        }
    }
    
    delete nc;
    
    return 0;
}
