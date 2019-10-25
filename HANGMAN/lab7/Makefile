CC = gcc
CFLAGS =-Wall --std=c99 -g 
OBJECTS = main.o string.o
TESTOBJ = string.o unit_test.o test_def.o
ALL: string_driver unit_test
string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o string.o
unit_test: $(TESTOBJ)
	$(CC) $(CFLAGS) -o unit_test $(TESTOBJ)
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
clean:
	rm string_driver $(OBJECTS)
