CC=gcc
CFLAGS=-Wall -Werror -g
INCLUDES=./inc
SRCDIR=./src
SOURCES= $(SRCDIR)/functionalities.c \
         $(SRCDIR)/binary.c \
         $(SRCDIR)/register.c \
         $(SRCDIR)/header.c \
         $(SRCDIR)/csv.c \
         $(SRCDIR)/funcoes_fornecidas.c 
PROG=./main.c
BINARY=./binary 
INPUT_FILE = ./3.in

all: $(BINARY)

$(BINARY): $(SOURCES)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $^ $(PROG) -o $@

run: $(BINARY) 
	@$(BINARY) < $(INPUT_FILE)

valgrind: $(BINARY)
	@valgrind --leak-check=full --show-leak-kinds=all $(BINARY)

clean:
	@rm -rf $(BINARY)
