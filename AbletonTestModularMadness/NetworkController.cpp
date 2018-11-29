//
//  NetworkController.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 23/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "NetworkController.hpp"

// Idea: feed the network the vector and then feed "silence" until the network remains silent.

NetworkController::NetworkController() {
    network = new Network();
}

NetworkController::~NetworkController() {
    delete network;
}

void NetworkController::handleInput(const std::vector<std::string> &command) {
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
        std::copy(++command.begin(), command.end(), inputVector.begin());
        processAndPrint(inputVector);
    } else {
        std::cout << "Unknown input. Please try again." << std::endl;
    }
}

void NetworkController::processAndPrint(const std::vector<std::string> &input) {
    std::list<std::string> output;
    
    process(input, output);
    
    for (auto it = output.begin(); it != output.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void NetworkController::process(const std::vector<std::string> &input, std::list<std::string> &output) {
    long maxOutputSize = input.size() * 16;
    long currentOutputSize = 0;
    
    for (auto it = input.begin(); it != input.end() && currentOutputSize <= maxOutputSize; ++it) {
        std::string networkOutput;
        network -> process(*it, networkOutput);
        output.push_back(networkOutput);
        currentOutputSize++;
    }
    
    // We will now feed silence to the network until it remains silent. This will ensure that all DelayModules are emptied.
    std::string previousNetworkOutput;
    while (previousNetworkOutput != SILENCE && currentOutputSize <= maxOutputSize) {
        std::string networkOutput;
        network -> process(SILENCE, networkOutput);
        output.push_back(networkOutput);
        currentOutputSize++;
        previousNetworkOutput.resize(networkOutput.size());
        std::copy(networkOutput.begin(), networkOutput.end(), previousNetworkOutput.begin());
    }
}




