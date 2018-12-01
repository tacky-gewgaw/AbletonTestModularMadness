//
//  ModuleFactory.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "ModuleFactory.hpp"

BaseModule *ModuleFactory::create(const std::string &type) { 
    if (type == "delay") {
        return new DelayModule();
    } else if (type == "echo") {
        return new EchoModule();
    } else if (type == "noop") {
        return new NoopModule();
    } else if (type == "reverse") {
        return new ReverseModule();
    }
    return new NoopModule();
}
