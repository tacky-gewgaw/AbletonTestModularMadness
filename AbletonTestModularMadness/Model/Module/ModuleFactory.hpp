//
//  ModuleFactory.hpp
//  src
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
    static Module *create(const string &type);
};

#endif /* ModuleFactory_hpp */
