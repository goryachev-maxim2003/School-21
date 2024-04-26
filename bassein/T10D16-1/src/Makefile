CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
DIRECTORY = ../build/

# start1: strlen_tests
# 	./$(DIRECTORY)Quest_1
# start2: strcmp_tests
# 	./$(DIRECTORY)Quest_2
# start3: strcpy_tests
# 	./$(DIRECTORY)Quest_3
# start4: strcat_tests
# 	./$(DIRECTORY)Quest_4
# start5: strchr_tests
# 	./$(DIRECTORY)Quest_5
# start6: strstr_tests
# 	./$(DIRECTORY)Quest_6

strlen_tests : s21_string.o
	$(CC) $(CFLAGS) -DQuest_1 s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(DIRECTORY)Quest_1
strcmp_tests: s21_string.o 
	$(CC) $(CFLAGS) -DQuest_2 s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(DIRECTORY)Quest_2
strcpy_tests: s21_string.o 
	$(CC) $(CFLAGS) -DQuest_3 s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(DIRECTORY)Quest_3
strcat_tests: s21_string.o 
	$(CC) $(CFLAGS) -DQuest_4 s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(DIRECTORY)Quest_4
strchr_tests: s21_string.o 
	$(CC) $(CFLAGS) -DQuest_5 s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(DIRECTORY)Quest_5
strstr_tests: s21_string.o 
	$(CC) $(CFLAGS) -DQuest_6 s21_string_test.c
	$(CC) s21_string.o s21_string_test.o -o $(DIRECTORY)Quest_6

s21_string_test.o : s21_string_test.c s21_string.h
s21_string.o: s21_string.h s21_string.c
	$(CC) $(CFLAGS) s21_string.c
clean:
	rm *.o $(DIRECTORY)Quest*