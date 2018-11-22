//
//  ReverseModule.cpp
//  AbletonTestModularMadness
//
//  Created by Sander van Kasteel on 21/11/2018.
//  Copyright © 2018 Sander van Kasteel. All rights reserved.
//

#include "ReverseModule.hpp"

void ReverseModule::process() {

}

string ReverseModule::process(string in) {
    reverse(in.begin(), in.end());
    return in;
}
