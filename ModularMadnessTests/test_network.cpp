//
//  test_network.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 03/12/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include <stdio.h>
#include "catch.hpp"
#include "../ModularMadness/Model/Network.hpp"

TEST_CASE("A network strusture can be defined by calling its methods", "[network]") {
    Network* testNetwork = new Network();
    
//    SECTION("When ") {
//        testNetwork -> makeModule("alpha", "reverse");
//        testNetwork -> makeModule("beta", "delay");
//    }
    
    // TODO: methods to test:
    // testNetwork -> makeModule(name, type);
    // testNetwork -> makeConnection(name1, name2);
    
    delete testNetwork;
}
