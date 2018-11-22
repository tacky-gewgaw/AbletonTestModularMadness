//
//  ModuleFactory.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef ModuleFactory_hpp
#define ModuleFactory_hpp

#include <stdio.h>
#include "NoopModule.hpp"
#include "EchoModule.hpp"
#include "DelayModule.hpp"
#include "ReverseModule.hpp"

class ModuleFactory {
public:
    Module *create(const std::string &type);
};

#endif /* ModuleFactory_hpp */
