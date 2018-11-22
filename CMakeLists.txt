cmake_minimum_required(VERSION 3.12)
project(AbletonTestModularMadness)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/Model)
include_directories(src/Model/Module)

add_library(AbletonTestModularMadnessModel
        src/Model/Module/DelayModule.cpp
        src/Model/Module/DelayModule.hpp
        src/Model/Module/EchoModule.cpp
        src/Model/Module/EchoModule.hpp
        src/Model/Module/Module.cpp
        src/Model/Module/Module.hpp
        src/Model/Module/ModuleFactory.cpp
        src/Model/Module/ModuleFactory.hpp
        src/Model/Module/NoopModule.cpp
        src/Model/Module/NoopModule.hpp
        src/Model/Module/ReverseModule.cpp
        src/Model/Module/ReverseModule.hpp
        src/Model/Network.cpp
        src/Model/Network.hpp
        )
add_executable(AbletonTestModularMadness
        src/catch.hpp
        src/main.cpp
        )
link_libraries(AbletonTestModularMadnessModel AbletonTestModularMadness)
