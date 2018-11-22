cmake_minimum_required(VERSION 3.12)
project(AbletonTestModularMadness)

set(CMAKE_CXX_STANDARD 14)

include_directories(AbletonTestModularMadness)
include_directories(AbletonTestModularMadness/Model)
include_directories(AbletonTestModularMadness/Model/Module)

add_library(AbletonTestModularMadnessModel
        AbletonTestModularMadness/Model/Module/DelayModule.cpp
        AbletonTestModularMadness/Model/Module/DelayModule.hpp
        AbletonTestModularMadness/Model/Module/EchoModule.cpp
        AbletonTestModularMadness/Model/Module/EchoModule.hpp
        AbletonTestModularMadness/Model/Module/Module.cpp
        AbletonTestModularMadness/Model/Module/Module.hpp
        AbletonTestModularMadness/Model/Module/ModuleFactory.cpp
        AbletonTestModularMadness/Model/Module/ModuleFactory.hpp
        AbletonTestModularMadness/Model/Module/NoopModule.cpp
        AbletonTestModularMadness/Model/Module/NoopModule.hpp
        AbletonTestModularMadness/Model/Module/ReverseModule.cpp
        AbletonTestModularMadness/Model/Module/ReverseModule.hpp
        AbletonTestModularMadness/Model/Network.cpp
        AbletonTestModularMadness/Model/Network.hpp
        )
add_executable(AbletonTestModularMadness
        AbletonTestModularMadness/catch.hpp
        AbletonTestModularMadness/main.cpp
        )
link_libraries(AbletonTestModularMadnessModel AbletonTestModularMadness)
