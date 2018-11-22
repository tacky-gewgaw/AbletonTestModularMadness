//
//  Network.hpp
//  src
//
//  Created by Sander van Kasteel on 20/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include <map>
#include "Module/ModuleFactory.hpp"

using namespace std;

class Network {
private:
    map<string,Module*> moduleRegistry = {};
    list<Module*> modulesInOrder = {};
public:
    void makeModule(const std::string &name, const std::string &type);
    void makeConnection(const std::string &name1, const std::string &name2);
    void process(const std::string &input, const std::string &output);
    string process(const string in);
};

#endif /* Network_hpp */
