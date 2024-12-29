CPP = g++
CPPFLAGS =

.PHONY: pass1 pass2 clean

pass1: 
	$(CPP) -Dpass1 io_ops.cc -o a.out
	./a.out

pass2:
	$(CPP) -Dpass2 io_ops.cc -o a.out
	./a.out

clean:
	rm -f a.out