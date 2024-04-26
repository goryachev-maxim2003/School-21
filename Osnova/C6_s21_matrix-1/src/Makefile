.PHONY: all s21_decimal.a

CC=gcc
FLAGS=-std=c11 -Wall -Werror -Wextra
TEST_FLAGS=-lm
S21_MATRIX_C=s21_*.c
S21_MATRIX_H=s21_*.h
S21_MATRIX_O=s21_*.o
TESTS=tests


ifeq ($(shell uname -s),Linux)
	TEST_FLAGS+=-lsubunit
endif

all: s21_matrix.a

s21_matrix.a:
	$(CC) $(S21_MATRIX_C) -c $(FLAGS)
	ar rc s21_matrix.a $(S21_MATRIX_O)
	ranlib s21_matrix.a

s21_covered:
	$(CC) $(S21_MATRIX_C) -c $(FLAGS) --coverage
	ar rc s21_matrix.a $(S21_MATRIX_O)
	ranlib s21_matrix.a

style:
	clang-format -style=google -i test/*.c *.c *.h
	clang-format -style=google -n test/*.c *.c *.h

test: clean s21_covered
	$(CC) test/$(TESTS)*.c $(TESTS).c -c $(FLAGS) --coverage
	$(CC) function_for_testing.c -c $(FLAGS)
	$(CC) -o $(TESTS) $(TESTS)*.o function_for_testing.o s21_matrix.a -lcheck --coverage $(FLAGS) $(TEST_FLAGS) -lgcov
	./$(TESTS)

mem_test: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TESTS)
else
	leaks --atExit -- ./$(TESTS)
endif

clean:
	rm -rf $(TESTS) *.a *.o *.gcda *.gcno *.gcov *.info *.html report

rebuild: clean all

gcov_report: test
	lcov -t "s21_matrix" -o s21_matrix.info -c -d .
	genhtml -o report s21_matrix.info
#	open report/index.html

my_test: s21_matrix.a
	$(CC) $(FLAGS) my_test_folder/my_test.c s21_matrix.a -o tests_max
	./tests_max

mem_my_test: s21_matrix.a
	$(CC) $(FLAGS) my_test_folder/my_test.c s21_matrix.a -o tests_max
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./tests_max
else
	leaks --atExit -- ./tests_max
endif
	
	