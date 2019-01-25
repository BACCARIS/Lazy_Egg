CC=g++
CFLAGS=-Wall -std=c++0x -g
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXEC=projet
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

projet: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

main.o: *.h

%.o: %.cc
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o $(EXEC)

mrproper: clean
	@rm -rf $(EXEC)
