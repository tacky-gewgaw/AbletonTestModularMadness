//
//  Network.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 20/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "Network.hpp"

//The input defines a network of modules and a stream of input into this network. This input
//stream should be fed into the first module (in the order of definition) and the output of the
//program should correspond to the output of the last module. If there are multiple input
//connections for a module, they should be “summed” before feeding to the module. Summing
//works by appending the strings in the order in which the input connections have been made.
//The individual modules should be processed in the order they have been defined.1 The
//network should only process one string at a time. Each process statement should let the
//network run empty (see also the example below).

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
    
    if (first == nullptr) {
        output.resize(input.size());
        std::copy(input.begin(), input.end(), output.begin());
        return;
    }
    
    first -> feedInput(input);
    
    std::list<Module*>::iterator it = modulesInOrder.begin();
    for (it; it != modulesInOrder.end(); it++) {
        
    }
    
    output.resize(input.size());
    std::copy(input.begin(), input.end(), output.begin());
}




