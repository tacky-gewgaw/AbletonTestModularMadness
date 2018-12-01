//
//  ReverseModule.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef ReverseModule_hpp
#define ReverseModule_hpp

#include <stdio.h>
#include "BaseModule.hpp"

class ReverseModule : public BaseModule {
public:
    ~ReverseModule();
    void generateOutput();
    void reset();
};

#endif /* ReverseModule_hpp */
