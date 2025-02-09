# Project Name: Testing Casting Capabilities on the Counter Class

This project implements a Counter class in C++ and then tests various Explicit Type Conversion Capabilities. Explicit type conversion, also known as casting, is when you, the programmer, explicitly tell the compiler to convert a value from one type to another
 
Key Type Conversion Methods tested are:

- Explicit Casting
    - Static Casting: Type checking is done at compile time, used for most common conversions where the compiler can perform the conversion implicitly. It's generally preferred over C-style casts.
    - Dynamic Casting: dynamic_cast is specifically designed for conversions involving polymorphic classes (classes with at least one virtual function). It performs a runtime check to ensure that the conversion is valid. If the object pointed to by the pointer is not of the target type (or a derived type), dynamic_cast returns nullptr (for pointers) or throws a std::bad_cast exception (for references). This is beneficial when you are downcasting (converting a pointer or reference from a base class to a derived class) in a polymorphic hierarchy, and you need to ensure that the object is actually of the derived type before using it as such. Dynamic Casting is crucial for type safety in polymorphic situations.
    - Const Casting: const_cast is used to add or remove the const or volatile qualifiers from a variable. This is generally discouraged unless you have a very specific reason to do so (e.g., interfacing with a library that doesn't use const correctly). Misuse of const_cast can lead to const correctness issues and unexpected behavior.
    - Reinterpret Casting: reinterpret_cast is the most powerful and most dangerous cast. It performs a low-level, bit-by-bit reinterpretation of the data. It can convert between unrelated pointer types (e.g., int* to void* to float*), and it can even convert between pointers and integers. reinterpret_cast does not perform any type checking.
## Description

### Program Structure:


- casting_counter.h:        Header file containing the Counter class declaration
- casting_counter.cpp:      Implementation of Counter class methods
- counter_test.cpp:         Test program that exercises Counter functionality
- Makefile:                 Build automation


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
