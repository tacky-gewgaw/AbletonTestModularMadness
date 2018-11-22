//
//  Module.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "Module.hpp"

void Module::connnectOutputTo(Module *m) {
    connectionsOut.push_back(m);
}

void Module::feedInput(const string &value) {
    input += value;
}

void Module::getOutput(string &result) {
    // output.copy(result, output.size(), 0);
}



