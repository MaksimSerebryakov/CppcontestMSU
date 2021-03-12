all: complex.o complex_stack.o polish_notation.o integral.o main.o
	g++ $^ -o run
main.o: main.cpp
	g++ -c main.cpp
complex.o: src/complex.cpp
	g++ -c src/complex.cpp
complex_stack.o: src/complex.cpp
	g++ -c src/complex_stack.cpp
integral.o: src/integral.cpp
	g++ -c src/integral.cpp
polish_notation.o: src/polish_notation.cpp
	g++ -c src/polish_notation.cpp
clean: 
	rm -rf *.o run