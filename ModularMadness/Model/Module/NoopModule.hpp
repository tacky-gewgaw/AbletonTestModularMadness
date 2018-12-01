//
//  NoopModule.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef NoopModule_hpp
#define NoopModule_hpp

#include <stdio.h>
#include "BaseModule.hpp"

class NoopModule : public BaseModule {
public:
    ~NoopModule();
    void generateOutput();
    void reset();
};

#endif /* NoopModule_hpp */
