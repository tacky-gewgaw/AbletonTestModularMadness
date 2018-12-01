//
//  ReverseModule.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "ReverseModule.hpp"

// We reverse the input string and copy the result to the output
void ReverseModule::generateOutput() { 
    std::string result;
    getInput(result);
    
    output.resize(result.size());
    std::reverse_copy(result.begin(), result.end(), output.begin());
    
    clearInput();
}

void ReverseModule::reset() {
    clearInput();
    output.clear();
}

ReverseModule::~ReverseModule() { 
    clearAll();
}




