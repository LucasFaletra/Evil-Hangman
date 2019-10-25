CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o

unit_test: my_string.o unit_test.o test_def.o
	$(CC)$(CFLAGS)-o unit_test unit_test.o test_def.o my_string.o

unit_test.o:

test_def.o:

string_driver:$(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
string.o:my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o string.o
clean:
	rm string_driver $(OBJECTS)
