//
//  DelayModule.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef DelayModule_hpp
#define DelayModule_hpp

#include <stdio.h>
#include "BaseModule.hpp"

class DelayModule : public BaseModule {
private:
    const std::string defaultValue = "hello";
    std::string buffer;
public:
    DelayModule();
    ~DelayModule();
    void generateOutput();
    void reset();
};

#endif /* DelayModule_hpp */
