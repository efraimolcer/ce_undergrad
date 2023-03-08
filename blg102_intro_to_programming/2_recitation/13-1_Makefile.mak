CC = gcc
CFLAGS = -std=c99 -Wall -Werror
LFLAGS = -lgdbm -I./include

13-1_dictionary: 13-1_dictionary_core.o 13-1_dictionary_interface.o
	$(CC) 13-1_dictionary_core.o 13-1_dictionary_interface.o $(LFLAGS) -o 13-1_dictionary

13-1_dictionary_core.o: 13-1_dictionary_core.c
	$(CC) $(CFLAGS) -c 13-1_dictionary_core.c -o 13-1_dictionary_core.o

13-1_dictionary_interface.o: 13-1_dictionary_interface.c
	$(CC) $(CFLAGS) -c 13-1_dictionary_interface.c -o 13-1_dictionary_interface.o

clean:
	rm -f *.o