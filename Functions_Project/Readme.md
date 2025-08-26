# Project Name: Function Enhancement on the Counter Class

This project implements a Counter class in C++ demonstrating Object-Oriented implementation of different types of counters (Binary, BCD, and Gray Code), the project also involves a test program that verifies the functionality of the counter class using assertions.
 
Key features include:

- Three counting modes: Binary (BIN), Binary-Coded Decimal (BCD), and Gray Code (GRY)
- Support for different counting operations
- Copy/Move semantics for object management
- Static tracking of Counter objects
- Member functions for getting/setting counter values and modes

## Description

### Program Structure:


- func_counter.h:           Header file containing the Counter class declaration
- functions_counter.cpp:    Implementation of Counter class methods
- counter_test.cpp:         Test program that exercises Counter functionality
- Makefile:                  Build automation


## Build Process:

- The Makefile uses g++ compiler with warnings (-Wall) and debug info (-g)
- Compiles source files into object files (.o)
- Links object files into final executable
- Automatically handles dependencies (recompiles only when needed)

The Makefile automates:

- Compilation of source files
- Linking into executable
- Running tests
- Comparing test results
- Cleaning up generated files

## Running the Program

```bash
make
# or
make all      # This compiles all source files and creates the executable counter_test.exe

make run      # This builds (if needed) and executes the program

make test.log # This runs the program and saves output to counter_test.log

make clean    # Removes all generated files (executable, object files, logs)
```


## Additional Notes:

- Headers are properly guarded against multiple inclusion
- Test file includes assertions to verify class functionality
- Build process follows standard C++ compilation model


## License

This project is licensed under the GNU General Public License, Version 3 - see the [LICENSE.md](../LICENSE.md) file for details.

## Contact

- Author: Ujval Madhu
- Email: ujvalmadhu003@gmail.com

## Acknowledgments

- This Project was done as part of a project using instructions from Cadence Design Systems, Online Support Courses