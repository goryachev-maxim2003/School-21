CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
DIRECTORY = ../build/

# start1: print_module
# 	./$(DIRECTORY)Quest_1
# start2: documentation_module
# 	./$(DIRECTORY)Quest_2
# start3: bst_create_test
# 	leaks -atExit -- ./$(DIRECTORY)Quest_3
# #	./$(DIRECTORY)Quest_3
# start4: bst_insert_test
# 	leaks -atExit -- ./$(DIRECTORY)Quest_4
# #	./$(DIRECTORY)Quest_4
# start5: bst_traverse_test
# 	leaks -atExit -- ./$(DIRECTORY)Quest_5
# #	./$(DIRECTORY)Quest_5

print_module: print_module.o main_module_entry_point.o
	$(CC) print_module.o main_module_entry_point.o -o $(DIRECTORY)Quest_1
print_module.o: print_module.c print_module.h
	$(CC) $(CFLAGS) print_module.c
# documentation_module: main_module_entry_point.o documentation_module.o
# 	-o documentation_module.o main_module_entry_point.o $(DIRECTORY)Quest_2

# documentation_module.o: documentation_module.h documentation_module.c
# 	$(CC) $(CFLAGS) documentation_module.c

main_module_entry_point.o: main_module_entry_point.c print_module.h
	$(CC) $(CFLAGS) main_module_entry_point.c



bst_create_test: bst.o bst_create_test.o
	$(CC) bst.o bst_create_test.o -o $(DIRECTORY)Quest_3
bst_create_test.o: bst_create_test.c bst.h
	$(CC) $(CFLAGS) bst_create_test.c

bst_insert_test: bst.o bst_insert_test.o
	$(CC) bst.o bst_insert_test.o -o $(DIRECTORY)Quest_4
bst_insert_test.o: bst_insert_test.c bst.h
	$(CC) $(CFLAGS) bst_insert_test.c

bst_traverse_test: bst.o bst_traverse_test.o
	$(CC) bst.o bst_traverse_test.o -o $(DIRECTORY)Quest_5
bst_traverse_test.o: bst_traverse_test.c bst.h
	$(CC) $(CFLAGS) bst_traverse_test.c


bst.o: bst.c bst.h
	$(CC) $(CFLAGS) bst.c



clean:
	rm *.o $(DIRECTORY)Quest*
#new