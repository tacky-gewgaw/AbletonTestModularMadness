//
//  EchoModule.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef EchoModule_hpp
#define EchoModule_hpp

#include <stdio.h>
#include "BaseModule.hpp"

class EchoModule : public BaseModule {
public:
    ~EchoModule();
    void generateOutput();
    void reset();
};

#endif /* EchoModule_hpp */
