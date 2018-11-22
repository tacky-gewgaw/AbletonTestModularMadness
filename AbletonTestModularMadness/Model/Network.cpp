//
//  Network.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 20/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "Network.hpp"

Network::Network() {
    mf = new ModuleFactory();
}

Network::~Network() {
    delete mf;
    
    modulesInOrder.clear();
    moduleRegistry.clear();
}

void Network::makeModule(const std::string &name, const std::string &type) {
    Module* m = mf -> create(type);
    
    std::cout << "Creating " << type << " module called " << name << std::endl;
    modulesInOrder.push_back(m);
    moduleRegistry.insert(std::pair<std::string, Module*>(name, m));
}

void Network::makeConnection(const std::string &name1, const std::string &name2) {
    Module* outModule = moduleRegistry[name1];
    Module* inModule = moduleRegistry[name2];
    
    std::cout << "Connecting output of " << name1 << " with input of " << name2 << std::endl;
    
    outModule -> connnectOutputTo(inModule);
}

void Network::process(const std::string &input, std::string &output) {
    std::cout << "Processing " << input << std::endl;
    Module* first = modulesInOrder.front();
    
    first -> feedInput(input);
    
    std::list<Module*>::iterator it = modulesInOrder.begin();
    for (it; it != modulesInOrder.end(); it++) {
        
    }
    
    output = input;
}




