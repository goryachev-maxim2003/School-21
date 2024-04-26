CC=gcc
CCFLAGS= -c -Wall -Werror -Wextra -std=c11 -lm

start_leaks: test
	leaks -atExit -- ./test
start: test
	./test


test: stack.o p_t_d_test.o Postfix_to_double.o
	$(CC) stack.o p_t_d_test.o Postfix_to_double.o -o test
stack.o: stack.c stack.h
	$(CC) $(CCFLAGS) stack.c
p_t_d_test.o: p_t_d_test.c stack.h 
	$(CC) $(CCFLAGS) p_t_d_test.c
Postfix_to_double.o:
	$(CC) $(CCFLAGS) Postfix_to_double.c
clean:
	rm *.o test