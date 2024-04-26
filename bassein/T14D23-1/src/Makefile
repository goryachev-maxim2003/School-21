CCFLAGS = -c -Wall -Werror -Wextra -std=c11
CC = gcc
DERECTORY = ../build/

# all: state_sort
# 	leaks -atExit -- ./$(DERECTORY)Quest_1
# start2: state_search
# 	leaks -atExit -- ./$(DERECTORY)Quest_2
#	./$(DERECTORY)Quest_2

state_sort: state_sort.o times.o
	$(CC) state_sort.o times.o -o $(DERECTORY)Quest_1
state_sort.o:
	$(CC) $(CCFLAGS) state_sort.c

state_search: state_search.o times.o
	$(CC) state_search.o times.o -o $(DERECTORY)Quest_2
state_search.o:
	$(CC) $(CCFLAGS) state_search.c

times.o:
	$(CC) $(CCFLAGS) times.c
clean:
	rm *.o $(DERECTORY)*