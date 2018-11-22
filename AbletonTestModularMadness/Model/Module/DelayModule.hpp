//
//  DelayModule.hpp
//  src
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
    string previousOutput = "hello";
public:
    void process() override;

    string process(string string1) override;
};

#endif /* DelayModule_hpp */
