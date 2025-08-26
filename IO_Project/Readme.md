# Project Name: IO Operations

The program demonstrates file I/O operations in C++ with two distinct execution passes controlled by preprocessor directives (pass1 and pass2):

## Features

The code effectively demonstrates:

- Binary file I/O
- Struct serialization
- User input validation
- Preprocessor directives for different execution modes
- Time manipulation in C++
- Error handling

## Running the Program

```bash
make pass1    # To run the first pass (write to file)
make pass2    # To run the second pass (read from file)
make clean    # To clean up the executable
```

## Description

### Structure Definition:


UserDetails struct stores:

User's name (char array)
Birth date (day, month, year as integers)
A method calculate_age() that computes current age using system time


- Pass1 Mode (-Dpass1):


Opens a file "user_data.txt" for writing
Takes user input with validation:

Name using getline()
Birth date with error checking for valid ranges


Writes the entire struct to file using binary write (write())


- Pass2 Mode (-Dpass2):


Opens the same file for reading
Reads the struct data using binary read (read())
Displays user's name and calculated age


- Error Handling:


Validates file operations
Includes input validation for date components
Uses cin.clear() and cin.ignore() for robust input handling

## License

This project is licensed under the GNU General Public License, Version 3 - see the [LICENSE.md](../LICENSE.md) file for details.

## Contact

- Author: Ujval Madhu
- Email: ujvalmadhu003@gmail.com

## Acknowledgments

- This Project was done as part of a project using instructions from Cadence Design Systems, Online Support Courses