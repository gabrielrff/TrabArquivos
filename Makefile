CC=gcc
INCLUDES=./inc
SOURCES= ./src/functionalities.c ./src/binary.c ./src/register.c ./src/header.c ./src/csv.c ./src/funcoes_fornecidas.c
PROG=./main.c
BINARY=./binary 

all:
	@$(CC) $(PROG) -Wall -Werror -g $(SOURCES) -I$(INCLUDES) -o $(BINARY)

run:
	@$(BINARY) 

valgrind:
	@-valgrind --leak-check=full --show-leak-kinds=all $(BINARY)

clean:
	@rm -rf *.o $(BINARY) 