# Project Name: Reference Variable and Ref-Qualified Function Implementation on a Counter Class

The program demonstrates several modern C++ features by enhancing the counter class from the previous project, these features are:

- Reference member variables
- Member function ref-qualifications
- Value category based function overloading
- Move semantics (in the rvalue version)

This design allows for:

- Direct manipulation of the counter's value through either value or ref_value
- Different behavior based on whether operations are performed on temporary or named objects
- Type-safe operations that prevent misuse of temporary objects
- Clear distinction between operations on persistent objects vs temporary ones

The combination of reference members and ref-qualified functions makes this a good example of how C++ can enforce proper object lifetime and value category semantics while maintaining efficiency and safety.

## Description

### Program Structure:


- ref_counter.h   (Header file with class declaration)
- ref_counter.cpp (Implementation file with method definitions)
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

- This Project was done using instructions from Cadence Design Systems, Online Support Courses