BINFILES = main.o global.o substitution.o word.o key_expansion.o matrix.o galois_field.o round.o
COMPILE_FLAGS = -g -c

all: $(BINFILES)
	g++ $(BINFILES) -o aes
main.o: main.cpp
	g++ $(COMPILE_FLAGS) main.cpp
global.o: global.h global.cpp
	g++ $(COMPILE_FLAGS) global.cpp
substitution.o: substitution.h substitution.cpp
	g++ $(COMPILE_FLAGS) substitution.cpp
word.o: word.cpp word.h
	g++ $(COMPILE_FLAGS) word.cpp
key_expansion.o: key_expansion.cpp key_expansion.h 
	g++ $(COMPILE_FLAGS) key_expansion.cpp
galois_field.o: galois_field.cpp galois_field.h
	g++ $(COMPILE_FLAGS) galois_field.cpp
matrix.o: matrix.cpp matrix.h
	g++ $(COMPILE_FLAGS) matrix.cpp
round.o: round.cpp round.h
	g++ $(COMPILE_FLAGS) round.cpp
clean:
	rm $(BINFILES)
