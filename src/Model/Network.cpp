//
//  Network.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 20/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "Network.hpp"

void Network::makeModule(const string &name, const string &type) {
    Module *m = ModuleFactory::create(type);
    modulesInOrder.push_back(m);
    moduleRegistry.insert(pair<string, Module *>(name, m));

}

void Network::makeConnection(const string &name1, const string &name2) {
    Module *outModule = moduleRegistry[name1];
    Module *inModule = moduleRegistry[name2];

    outModule->connnectOutputTo(inModule);
}

void Network::process(const std::string &input, const std::string &output) {
    Module *first = modulesInOrder.front();

    first->feedInput(input);

}

string Network::process(const string in) {
    string out (in);
    for (auto moduleIterator = modulesInOrder.begin(); moduleIterator != modulesInOrder.end(); ++moduleIterator) {
        out = (*moduleIterator)->process(out);
    }

    return out;
}




