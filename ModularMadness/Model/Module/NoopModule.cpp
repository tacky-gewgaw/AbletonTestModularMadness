//
//  NoopModule.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "NoopModule.hpp"

// Just copy the value behind input to output, then clear the input
void NoopModule::generateOutput() {
    getInput(output);
    clearInput();
}

void NoopModule::reset() {
    clearInput();
    output.clear();
}

NoopModule::~NoopModule() { 
    clearAll();
}




