BIN_FILES = main register input message_schedeuler global round
EXECUTABLE = sha512
CMP_FLAGS = -g -c
all: $(BIN_FILES)
	g++ $(BIN_FILES) -o $(EXECUTABLE)
main: main.cpp
	g++ $(CMP_FLAGS) main.cpp -o main
register: register.cpp register.h
	g++ $(CMP_FLAGS) register.cpp -o register
input: take_input.cpp take_input.h
	g++ $(CMP_FLAGS) take_input.cpp -o input
message_schedeuler: message_schedeuler.cpp message_schedeuler.h
	g++ $(CMP_FLAGS) message_schedeuler.cpp -o message_schedeuler
global: global.h global.cpp
	g++ $(CMP_FLAGS) global.cpp -o global
round: round.cpp round.h
	g++ $(CMP_FLAGS) round.cpp -o round
clean:
	rm $(BIN_FILES) *~ $(EXECUTABLE)
