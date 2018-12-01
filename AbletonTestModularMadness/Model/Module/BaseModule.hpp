//
//  Module.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef Module_hpp
#define Module_hpp

#include <stdio.h>
#include <iostream>
#include <list>

class BaseModule {
private:
    // We don't want the input to be freely accessible, as it usually needs to be computed
    std::string input;
protected:
    std::list<BaseModule*> connectionsIn = {};
    std::string output;
    void getInput(std::string &result);
    void clearInput();
    void clearAll();
public:
    virtual void generateOutput() = 0;
    virtual void reset() = 0;
    virtual ~BaseModule();
    void connnectToOutputOf(BaseModule* m);
    void overrideInput(const std::string &value);
    void getOutput(std::string &result);
};

#endif /* Module_hpp */
