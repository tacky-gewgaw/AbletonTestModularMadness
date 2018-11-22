//
//  Module.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef Module_hpp
#define Module_hpp

#include <stdio.h>
#include <iostream>
#include <list>

class Module {
protected:
    std::list<Module*> connectionsOut = {};
    std::string output = "";
    std::string input = "";
public:
    void connnectOutputTo(Module* m);
    void feedInput(const std::string &value);
    void getOutput(std::string &result);
//    virtual void process();
};

#endif /* Module_hpp */
