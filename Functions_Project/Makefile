CPP = g++
CPPFLAGS = -Wall -g  # Adds warnings and debug information

# Final executable
EXEC = counter_test.exe

# Object files needed
OBJECTS = functions_counter.o counter_test.o

# Default target
all: $(EXEC)

# Linking rule
$(EXEC): $(OBJECTS)
	$(CPP) $(OBJECTS) -o $(EXEC)

# Compilation rules for object files # object file should match the CPP file
functions_counter.o: functions_counter.cpp func_counter.h
	$(CPP) $(CPPFLAGS) -c functions_counter.cpp

counter_test.o: counter_test.cpp func_counter.h
	$(CPP) $(CPPFLAGS) -c counter_test.cpp

# Run the tests
test.log: $(EXEC)
	./$(EXEC) > counter_test.log 2>&1

# Compare with saved output
diff: test.log
	diff counter_test_save.log counter_test.log

# Clean up
clean:
	rm -f $(EXEC) $(OBJECTS) counter_test.log

# Run the program
run: $(EXEC)
	./$(EXEC)