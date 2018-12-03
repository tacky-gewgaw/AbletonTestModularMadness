//
//  test_modules.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 01/12/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "catch.hpp"
#include "../ModularMadness/Model/Module/NoopModule.hpp"
#include "../ModularMadness/Model/Module/DelayModule.hpp"
#include "../ModularMadness/Model/Module/EchoModule.hpp"
#include "../ModularMadness/Model/Module/ReverseModule.hpp"

const std::vector<std::string> inputStrings = {"do", "re", "mi", "fa", "sol", "la", "ti"};

TEST_CASE("A Module inheriting from BaseModule generates its input as an in order concatenation of the outputs of its predecessing Modules", "[base-module]") {
    BaseModule* m = new NoopModule();
    
    const std::string expectedResult = "doremifasollati";
    std::vector<BaseModule*> outputModules = {
        new NoopModule(),
        new NoopModule(),
        new NoopModule(),
        new NoopModule(),
        new NoopModule(),
        new NoopModule(),
        new NoopModule()
    };
    
    int i = 0;
    for (BaseModule* o : outputModules) {
        std::string input = inputStrings[i];
        o -> overrideInput(input);
        o -> generateOutput();
        m -> connnectToOutputOf(o);
        i++;
    }
    
    m -> generateOutput();
    
    std::string actualResult;
    m -> getOutput(actualResult);
    
    REQUIRE(expectedResult == actualResult);
    
    for (BaseModule* o : outputModules) {
        delete o;
    }
    delete m;
    
    outputModules.clear();
    
    actualResult.clear();
}

TEST_CASE("The output of a NoopModule equals its input", "[noop-module]") {
    NoopModule noopModule;
    
    for (std::string s : inputStrings) {
        noopModule.overrideInput(s);
        noopModule.generateOutput();
        std::string result;
        noopModule.getOutput(result);
        REQUIRE(s == result);
    }
}

TEST_CASE("The output of a ReverseModule equals the reverse of its input", "[reverse-module]") {
    ReverseModule reverseModule;
    
    const std::vector<std::string> expectedOutputStrings = {"od", "er", "im", "af", "los", "al", "it"};
    
    for (int i = 0; i < inputStrings.size(); i++) {
        reverseModule.overrideInput(inputStrings[i]);
        reverseModule.generateOutput();
        std::string result;
        reverseModule.getOutput(result);
        REQUIRE(expectedOutputStrings[i] == result);
    }
}

TEST_CASE("The output of a DelayModule equals its previous input", "[delay-module]") {
    DelayModule delayModule;
    
    const std::vector<std::string> expectedOutputStrings = {"hello", "do", "re", "mi", "fa", "sol", "la"};
    
    for (int i = 0; i < inputStrings.size(); i++) {
        delayModule.overrideInput(inputStrings[i]);
        delayModule.generateOutput();
        std::string result;
        delayModule.getOutput(result);
        REQUIRE(expectedOutputStrings[i] == result);
    }
}

TEST_CASE("The output of an EchoModule equals the a concatenation of the input with itself", "[echo-module]") {
    EchoModule echoModule;
    
    const std::vector<std::string> expectedOutputStrings = {"dodo", "rere", "mimi", "fafa", "solsol", "lala", "titi"};
    
    for (int i = 0; i < inputStrings.size(); i++) {
        echoModule.overrideInput(inputStrings[i]);
        echoModule.generateOutput();
        std::string result;
        echoModule.getOutput(result);
        REQUIRE(expectedOutputStrings[i] == result);
    }
}
