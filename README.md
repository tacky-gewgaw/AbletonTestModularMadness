# AbletonTestModularMadness

This is my solution to Task 3 as part of my application for C++ Developer at Ableton.
Be aware that this is the first time I have ever written C++ code. Therefore, this is mainly a showcase of my general understanding of the Object Oriented paradigm, my ability to solve complex problems, and my ability to understand a new programming language in a short time and well enough to use it to express my own algorithms.

## Compiling and running the program
The program was written in MacOSX using XCode. The following instructions should work from any bash terminal.
From /ModularMadness, enter:

```g++ -std=c++11 main.cpp NetworkController.cpp Model/Network.cpp Model/Module/BaseModule.cpp Model/Module/DelayModule.cpp Model/Module/EchoModule.cpp Model/Module/NoopModule.cpp Model/Module/ReverseModule.cpp Model/Module/ModuleFactory.cpp -o ModularMadness```

This should compile the source code to an executable called "ModularMadness".
To run, enter `./ModularMadness` from the same folder.

## Using the program
While ModularMadness is running, you have the following commands at your disposal:
- `module <name> <type>`, where type is one of `delay`, `echo`, `noop`, and `reverse`.
- `connect <module_name1> <module_name2>`, where the names should be the names of modules defined by a call with the `module` command.
- `process <input>`, where input is a line of strings separated by white spaces.
- `quit` to quit the program.

## Testing the program
TODO
