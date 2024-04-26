CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
DIRECTORY = ../build/

# start1: door_struct
# 	./$(DIRECTORY)Quest_1
# start2: list_test
# 	leaks -atExit -- ./$(DIRECTORY)Quest_2
# #	./$(DIRECTORY)Quest_2
# start3: stack_test
# 	leaks -atExit -- ./$(DIRECTORY)Quest_3
# #	./$(DIRECTORY)Quest_3


door_struct: dmanager_module.o
	$(CC) dmanager_module.o -o $(DIRECTORY)Quest_1
dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) dmanager_module.c

list_test: list.o list_test.o
	$(CC) list.o list_test.o -o $(DIRECTORY)Quest_2
list.o: list.c list.h door_struct.h
	$(CC) $(CFLAGS) list.c 
list_test.o: list_test.c door_struct.h list.h
	$(CC) $(CFLAGS) list_test.c

stack_test: stack.o stack_test.o
	$(CC) stack.o stack_test.o -o $(DIRECTORY)Quest_3
stack_test.o: stack_test.c stack.h
	$(CC) $(CFLAGS) stack_test.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c 

clean:
	rm *.o $(DIRECTORY)Quest*