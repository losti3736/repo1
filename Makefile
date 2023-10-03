// generate object files (.o)
output: main.o List.o
	// compile/build command
    g++ -std=c++11 -o output main.o List.o

// Rule for generating main.o file
main.o: main.cpp
    g++ -std=c++11 -c main.cpp

// Rule for generating List.o file
List.o: List.h List.cpp
	g++ -std=c++11 -c List.cpp

// Rule for cleaning project
clean:
    rm output main.o List.o
