//
//  DelayModule.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef DelayModule_hpp
#define DelayModule_hpp

#include <stdio.h>
#include "Module.hpp"

class DelayModule : public Module {
private:
    const std::string defaultValue = "hello";
    std::string buffer;
public:
    DelayModule();
    void reset();
};

#endif /* DelayModule_hpp */
