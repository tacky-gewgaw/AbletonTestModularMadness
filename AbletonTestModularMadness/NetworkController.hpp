//
//  NetworkController.hpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 23/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#ifndef NetworkController_hpp
#define NetworkController_hpp

#include <stdio.h>
#include <vector>
#include "Network.hpp"

class NetworkController {
private:
    Network* network;
    const std::string SILENCE = "";
    void processAndPrint(const std::vector<std::string> &input);
    void process(const std::vector<std::string> &input, std::list<std::string> &output);
public:
    NetworkController();
    ~NetworkController();
    void handleInput(const std::vector<std::string> &command);
};

#endif /* NetworkController_hpp */
