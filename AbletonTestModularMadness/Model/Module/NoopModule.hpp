//
//  NoopModule.hpp
//  src
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef NoopModule_hpp
#define NoopModule_hpp

#include <stdio.h>
#include "Module.hpp"

class NoopModule : public Module {
public:
    void process() override;

    string process(string in) override;
};

#endif /* NoopModule_hpp */
