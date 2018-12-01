//
//  EchoModule.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "EchoModule.hpp"

// We fetch the input, echo it and copy the result into the output
void EchoModule::generateOutput() { 
    std::string currentInput;
    getInput(currentInput);
    std::string echoedInput = currentInput + currentInput;
    output.resize(echoedInput.size());
    std::copy(echoedInput.begin(), echoedInput.end(), output.begin());
    clearInput();
}

void EchoModule::reset() {
    clearInput();
    output.clear();
}

EchoModule::~EchoModule() { 
    clearAll();
}

