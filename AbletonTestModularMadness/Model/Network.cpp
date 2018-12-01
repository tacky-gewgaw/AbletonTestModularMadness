//
//  Network.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 29/11/2018.
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
    
    moduleRegistry.clear();
    
    for (BaseModule* module : modulesInOrder) {
        delete module;
    }
    modulesInOrder.clear();
}

void Network::makeModule(const std::string &name, const std::string &type) {
    BaseModule* m = mf -> create(type);
    
    std::cout << "Creating " << type << " module called " << name << std::endl;
    modulesInOrder.push_back(m);
    moduleRegistry.insert(std::pair<std::string, BaseModule*>(name, m));
}

void Network::makeConnection(const std::string &name1, const std::string &name2) {
    BaseModule* outModule = moduleRegistry[name1];
    BaseModule* inModule = moduleRegistry[name2];
    
    std::cout << "Connecting output of " << name1 << " with input of " << name2 << std::endl;
    
    inModule -> connnectToOutputOf(outModule);
}

void Network::process(const std::string &input, std::string &output) {
    BaseModule* first = modulesInOrder.front();
    
    if (first == nullptr) {
        // When no modules are defined, copy the input string to the output string
        output.resize(input.size());
        std::copy(input.begin(), input.end(), output.begin());
        return;
    }
    
    first -> overrideInput(input);
    
    for (BaseModule* module : modulesInOrder) {
        module -> generateOutput();
    }
    
    BaseModule* last = modulesInOrder.back();
    last -> getOutput(output);
}

void Network::reset() {
    for (BaseModule* module : modulesInOrder) {
        module -> reset();
    }
}





