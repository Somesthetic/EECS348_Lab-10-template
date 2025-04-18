CC=g++ # Defines which compiler we're using
CFLAGS=-c -Wall

all: prog

prog: main.o calculator.o
	$(CC) main.o calculator.o -o result_prog # Says: compile all of these together, going to each, and save the
	# executable to result_prog

main.o: main.cpp calculator.hpp# Once prog calls this, it runs this, with main.c being a dependency
	$(CC) $(CFLAGS) main.cpp -o main.o # compiles main.c

calculator.o: calculator.cpp calculator.hpp
	$(CC) $(CFLAGS) calculator.cpp -o calculator.o # compiles main.c

clean:
	rm -rf *.o # Removes any file that ends in .o, using regex stuff