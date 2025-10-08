CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
LIBS = -ledit -lm

SOURCES = main.c lval.c lenv.c builtins.c eval.c read.c mpc.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = lispy

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

%.o: %.c lisp.h mpc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)