# Target: myprog, Dependencies: myprog.o
all: myprog.exe 


# Rule to create myprog from myprog.o
myprog.exe: myprog.o myprog2.o
	g++ myprog.o myprog2.o -o myprog.exe

# Rule to create myprog.o from myprog.cpp
myprog.o: myprog.cpp
	g++ -c myprog.cpp

myprog2.o: myprog2.cpp
	g++ -c myprog2.cpp

# Rule to clean up generated files
clean:
	rm -f *.o myprog.exe
