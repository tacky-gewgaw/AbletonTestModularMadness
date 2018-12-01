//
//  NetworkController.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "NetworkController.hpp"

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
        
        std::list<std::string> output;
        
        process(inputVector, output);
        
        for (auto it = output.begin(); it != output.end(); ++it)
            std::cout << *it << ' ';
        std::cout << std::endl;
    } else {
        // Print very basic instructions. We assume that all commands are entered correctly, as the assignment suggests.
        std::cout << "Unknown input. Available commands are:" << std::endl
        << "\t\"module <name> <type>\"" << std::endl
        << "\t\"connect <name1> <name2>\"" << std::endl
        << "\t\"process <input>\"" << std::endl;
    }
}

void NetworkController::process(const std::vector<std::string> &input, std::list<std::string> &output) {
    // Since the number of string in the output can be no more than sixteen times the number of strings in the input, we track the output size and interrupt the process when the maximum size is exceeded.
    long maxOutputSize = input.size() * 16;
    long currentOutputSize = 0;
    
    for (std::string word : input) {
        std::string networkOutput;
        network -> process(word, networkOutput);
        output.push_back(networkOutput);
        currentOutputSize++;
    }
    
    // We will now feed silence to the network until it remains silent. This will ensure that all DelayModules are emptied.
    std::string previousNetworkOutput = output.back();
    
    while (previousNetworkOutput != SILENCE && currentOutputSize <= maxOutputSize) {
        std::string networkOutput;
        network -> process(SILENCE, networkOutput);
        output.push_back(networkOutput);
        currentOutputSize++;
        
        previousNetworkOutput.resize(networkOutput.size());
        std::copy(networkOutput.begin(), networkOutput.end(), previousNetworkOutput.begin());
    }
    
    // Clear any remaining data from the network
    network -> reset();
}




