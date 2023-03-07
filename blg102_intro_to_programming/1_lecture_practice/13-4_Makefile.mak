CC = gcc
CFLAGS = -std=c99 -Wall -Werror

13-4_main: 13-4_main.o 13-4_cube.o
	$(CC) 13-4_main.o 13-4_cube.o -o 13-4_main

13-4_main.o: 13-4_main.c
	$(CC) $(CFLAGS) -c 13-4_main.c -o 13-4_main.o

13-4_cube.o: 13-4_cube.c
	$(CC) $(CFLAGS) -c 13-4_cube.c -o 13-4_cube.o

clean:
	rm -f *.o