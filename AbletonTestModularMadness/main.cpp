//
//  main.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 19/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
//#include "Model/Network.hpp"

using namespace std;

// Returns false if the command is terminal
void receive_input() {
    string command;

    getline(cin, command);
    istringstream iss(command);

    vector<string> results((std::istream_iterator<string>(iss)),
                           std::istream_iterator<string>());
    string type = results.at(0);
    if (type == "module") {
        cout << "Creating " << results.at(2) << " module called " << results.at(1) << endl;
    } else if (type == "connect") {
        cout << "Connecting output of " << results.at(1) << " with input of " << results.at(2) << endl;
    } else if (type == "process") {
        cout << "Processing " << results.at(1) << endl;
        return;
    } else {
        cout << "Unknown input. Please try again." << endl;
    }
    receive_input();
}

int main(int argc, const char * argv[]) {
    cout << "Welcome to Modular Madness!" << endl;
    
    receive_input();
    
    return 0;
}
