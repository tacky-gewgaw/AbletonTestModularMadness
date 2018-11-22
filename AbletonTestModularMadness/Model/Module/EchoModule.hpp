//
//  EchoModule.hpp
//  src
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef EchoModule_hpp
#define EchoModule_hpp

#include <stdio.h>
#include "Module.hpp"

class EchoModule : public Module {
public:
    string process(string in) override;

    void process() override;
};

#endif /* EchoModule_hpp */
