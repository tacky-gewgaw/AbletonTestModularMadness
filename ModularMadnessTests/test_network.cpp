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

const std::vector<std::string> inputStrings1 = {"do", "re", "mi", "fa", "sol", "la", "ti"};

TEST_CASE("A network with a reverse module connscted to a delay module returns the reverse of the previous input", "[network]") {
    Network testNetwork;
    
    testNetwork.makeModule("alpha", "reverse");
    testNetwork.makeModule("beta", "delay");
    testNetwork.makeConnection("alpha", "beta");
    
    const std::vector<std::string> expectedResults = {"hello", "od", "er", "im", "af", "los", "al"};
    
    for (int i = 0; i < inputStrings1.size(); i++) {
        std::string result;
        const std::string inputString = inputStrings1[i];
        testNetwork.process(inputString, result);
        REQUIRE(result == expectedResults[i]);
    }
}
