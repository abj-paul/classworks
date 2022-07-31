BIN_FILES = Word.o main.o global_constants.o

all: $(BIN_FILES)
	g++ $(BIN_FILES) -o executable

Word.o: Word.cpp Word.h global_constants.h
	g++ -c -g Word.cpp
main.o: main.cpp
	g++ -c -g main.cpp
global_constants.o: global_constants.cpp global_constants.h
	g++ -c -g global_constants.cpp
clean:
	rm $(BIN_FILES)
