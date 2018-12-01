//
//  DelayModule.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "DelayModule.hpp"

DelayModule::DelayModule() {
    buffer.resize(defaultValue.size());
    std::copy(defaultValue.begin(), defaultValue.end(), buffer.begin());
}

void DelayModule::reset() {
    clearInput();
    output.clear();
    
    buffer.resize(defaultValue.size());
    std::copy(defaultValue.begin(), defaultValue.end(), buffer.begin());
}

// We copy the buffered value to the output and set the current input as the new buffered value;
void DelayModule::generateOutput() {
    output.resize(buffer.size());
    std::copy(buffer.begin(), buffer.end(), output.begin());
    
    getInput(buffer);
    
    clearInput();
}

DelayModule::~DelayModule() { 
    clearAll();
    buffer.clear();
}





