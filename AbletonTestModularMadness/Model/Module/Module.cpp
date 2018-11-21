//
//  Module.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "Module.hpp"
#include "NoopModule.hpp"

void Module::connnectOutputTo(Module *m) {
    connectionsOut.push_back(m);
}
