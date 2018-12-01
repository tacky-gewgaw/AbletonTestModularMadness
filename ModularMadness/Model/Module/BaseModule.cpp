//
//  Module.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "BaseModule.hpp"

void BaseModule::connnectToOutputOf(BaseModule *m) {
    connectionsIn.push_back(m);
}

void BaseModule::overrideInput(const std::string &value) {
    input.resize(value.size());
    std::copy(value.begin(), value.end(), input.begin());
}

void BaseModule::getOutput(std::string &result) {
    result.resize(output.size());
    std::copy(output.begin(), output.end(), result.begin());
}

// If input is empty, loop through the input connections of this module and
// concatenate the outputs of those modules in order. Assign it to the input field
void BaseModule::getInput(std::string &result) {
    if (input.empty()) {
        for (BaseModule* outModule : connectionsIn) {
            std::string currentOutput;
            outModule -> getOutput(currentOutput);
            input += currentOutput;
        }
    }
    result.resize(input.size());
    std::copy(input.begin(), input.end(), result.begin());
}

void BaseModule::clearInput() {
    input.clear();
}

void BaseModule::clearAll() { 
    input.clear();
    connectionsIn.clear();
    output.clear();
}

BaseModule::~BaseModule() { 
    
}






