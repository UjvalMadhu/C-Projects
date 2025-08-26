CPP = g++
CPPFLAGS =

.PHONY: pass1 pass2 clean

ifeq ($(OS), Windows_NT)
	EXE = .exe
	RM = del /Q
else
	EXE = 
	RM = rm -f
endif

pass1:
	$(CPP) -Dpass1 io_ops.cc -o pass1$(EXE)
	./pass1$(EXE)

pass2:
	$(CPP) -Dpass2 io_ops.cc -o pass2$(EXE)
	./pass2$(EXE)

clean:
	$(RM) pass1$(EXE) pass2$(EXE)