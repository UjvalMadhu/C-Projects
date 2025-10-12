CC := gcc
CXX := g++

CFLAGS := -std=c99 -Wall
CXXFLAGS := -std=c++17 -Wall

# Name of File
SRC ?=

# Name for executable after compilation, removing .c or .cpp from file name
EXECUTABLE = $(basename $(SRC))

# Default target
all: compile run

# compile, (using [[]] allow for pattern matching within conditional blocks) 
compile:
		@if [ -z "$(SRC)" ]; then \
				echo "Error Please specify source file name as: make [TARGET] SRC=file_name.ext"
				exit 1; \
		fi
		@echo "Compiling $(SRC)..."
		@if [[ "$(SRC)" == *.cpp]]; then \
				$(CXX) $(CXXFLAGS) $(SRC) -o $(EXECUTABLE); \
		elif [[ "$(SRC)" == *.c ]]; then \
				 $(C) $(CFLAGS) $(SRC) -o $(EXECUTABLE); \
		else \
				echo "Error: Unsupported file extension, please use .c or .cpp files"; \
				exit 1; \
		fi

run: compile
		@if [ -f "$(EXECUTABLE)" ]; then \
				echo "Running $(EXECUTABLE)..."; \
				./$(EXECUTABLE); \
		else \
				echo "Error: Executable '$(EXECUTABLE)' not found, there could be a compilation error"; \
		fi


clean:
		@echo "Cleaning up..."
		rm -f $(EXECUTABLE)

