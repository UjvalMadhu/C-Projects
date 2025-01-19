# Project Name: Constructors and Destructors Implementation on a Counter Class

This project implements a Counter class in C++ demonstrating various Object-Oriented Programming concepts, the project also involves a test program that verifies the functionality of the counter class using assertions.

- Constructors (Default, Parameterized, Copy, Move)
- Assignment Operators (Copy and Move)
- Destructor
- Basic counter operations (get, set, increment)

## Description

### Program Structure:


- constr_destr_counter.h   (Header file with class declaration)
- constr_destr_counter.cpp (Implementation file with method definitions)
- counter_test.cpp         (Test file with assertions)
- Makefile                 (Build automation)


## Build Process:

- The Makefile uses g++ compiler with warnings (-Wall) and debug info (-g)
- Compiles source files into object files (.o)
- Links object files into final executable
- Automatically handles dependencies (recompiles only when needed)

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