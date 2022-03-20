run: main.o String.o Vector.o
	g++ main.o String.o -o run
main.o: main.cpp String.o Vector.o
	g++ -c -g main.cpp
String.o: String.h String.cpp
	g++ -c -g String.cpp
Vector.o: Vector.h
	g++ -c -g Vector.h
clean:
	rm *.o *.gch run
