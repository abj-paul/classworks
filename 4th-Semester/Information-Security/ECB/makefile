BINFILES = main.o global.o substitution.o word.o key_expansion.o matrix.o galois_field.o round.o
COMPILE_FLAGS = -g -c

all: $(BINFILES)
	g++ $(BINFILES) -o aes_app
main.o: main.cpp
	g++ $(COMPILE_FLAGS) main.cpp
global.o: aes/global.h aes/global.cpp
	g++ $(COMPILE_FLAGS) aes/global.cpp
substitution.o: aes/substitution.h aes/substitution.cpp
	g++ $(COMPILE_FLAGS) aes/substitution.cpp
word.o: aes/word.cpp aes/word.h
	g++ $(COMPILE_FLAGS) aes/word.cpp
key_expansion.o: aes/key_expansion.cpp aes/key_expansion.h 
	g++ $(COMPILE_FLAGS) aes/key_expansion.cpp
galois_field.o: aes/galois_field.cpp aes/galois_field.h
	g++ $(COMPILE_FLAGS) aes/galois_field.cpp
matrix.o: aes/matrix.cpp aes/matrix.h
	g++ $(COMPILE_FLAGS) aes/matrix.cpp
round.o: aes/round.cpp aes/round.h
	g++ $(COMPILE_FLAGS) aes/round.cpp
clean:
	rm $(BINFILES)
