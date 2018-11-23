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
public:
    NetworkController();
    ~NetworkController();
    void handleInput(std::vector<std::string> &input);
};

#endif /* NetworkController_hpp */
