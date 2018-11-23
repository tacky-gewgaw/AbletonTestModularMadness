//
//  NetworkController.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 23/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "NetworkController.hpp"

NetworkController::NetworkController() {
    network = new Network();
}

NetworkController::~NetworkController() {
    delete network;
}

void NetworkController::handleInput(std::vector<std::string> &command) {
    std::string calledFunction = command.at(0);
    
    if (calledFunction == "module") {
        std::string type = command.at(2);
        std::string name = command.at(1);
        network -> makeModule(name, type);
    } else if (calledFunction == "connect") {
        std::string name1 = command.at(1);
        std::string name2 = command.at(2);
        network -> makeConnection(name1, name2);
    } else if (calledFunction == "process") {
        std::vector<std::string> inputVector;
        inputVector.resize(command.size() - 1);
        std::copy(command.begin()++, command.end(), inputVector.begin());
        
        std::vector<std::string> outputVector;
        // network -> process(inputVector, outputVector);
        network -> clear();
        for (std::vector<std::string>::iterator it = outputVector.begin(); it != outputVector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    } else {
        std::cout << "Unknown input. Please try again." << std::endl;
    }
}
