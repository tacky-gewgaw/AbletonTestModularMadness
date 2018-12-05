# AbletonTestModularMadness

This is my solution to Task 3 as part of my application for C++ Developer at Ableton.
Be aware that this is the first time I have ever written C++ code. Therefore, this is mainly a showcase of my general understanding of the Object Oriented paradigm, my ability to solve complex problems, and my ability to understand a new programming language in a short time and well enough to use it to express my own algorithms.

I made some choices regarding the processing of strings to reduce the risk of memory leaks. For example, functions that transform a string are of the form `void functionName(const std::string &input, std::string &output)`, so both strings can be defined within the same scope.   

## Architecture
### Modules
All types of modules inherit from the BaseModule class. This abstract class gets its input from its connections, which are defined in a list within a module.

`BaseModule` also implements `overrideInput()`, which is only used when it is the input module and thus cannot get its input from other modules.

Each individual module type has its own implementation of `generateOutput()`, which converts the module's input to output.

Modules also contain a method `reset()`. For all modules, this clears the resources used by their input and output. A `DelayModule` has a special implementation, which defaults its buffered value to `"hello"`.

Modules are created by a `ModuleFactory`, which accepts the type in the form of a string and returns a pointer to a new Module of the correct type.

### Network
A network is responsible for storing modules and coordinating their output generation.

When `makeModule` is called, it asks the factory for a new Module. Then it adds the module to a list that defines their processing order, and to a module registry that maps a name to a pointer to the module.

By calling `makeConnection`, the names in the arguments are used to fetch the modules. The first module is then added as an incoming connection to the second module.

The method `process` processes a single string through the network by calling `overrideInput` on the first module in the list. Next, it calls `generateOutput` on the modules in the ordered list. Afterwards, it calls `getOutput` on the last module in the list for te result.

### NetworkController
The NetworkController is the interface between the terminal and the program's model. When `process <input>` is called in the terminal, it makes sure that the input strings are run through the network in order and that the network is cleared afterwards. It does this by feeding "silence" (i.e. empty strings) to the network until the network itself remains silent. This feature ensures that all delay modules have done their job. Afterwards, it resets the network to clear any buffered values and clear unneeded resources. 

## Compiling and running the program
The program was written in MacOSX using XCode. The following instructions should work from any bash terminal.
From /ModularMadness, enter:

```
g++ -std=c++11 main.cpp NetworkController.cpp Model/Network.cpp Model/Module/*.cpp -o ModularMadness
```

This should compile the source code to an executable called "ModularMadness".
To run, enter `./ModularMadness` from the same folder.

## Using the program
While ModularMadness is running, you have the following commands at your disposal:
- `module <name> <type>`, where type is one of `delay`, `echo`, `noop`, and `reverse`.
- `connect <module_name1> <module_name2>`, where the names should be the names of modules defined by a call with the `module` command.
- `process <input>`, where input is a line of strings separated by white spaces.
- `quit` to quit the program.

## Testing the program
As with compiling the program, compiling and running the tests can be done on a bash terminal using the following commands. From /ModularMadnessTests, enter:
```
g++ -std=c++11 -c tests_main.cpp
```
```
g++ -std=c++11 -o tests_runner tests_main.o test_network.cpp test_modules.cpp ../ModularMadness/Model/Module/*.cpp  ../ModularMadness/Model/Network.cpp
```
Then, to run the tests:
```
./tests_runner --success
```
