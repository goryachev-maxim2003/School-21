.PHONY: all s21_string.a

CC=gcc
CFLAGS=-std=c11 -g -Wall -Werror -Wextra
S21_STRING_C=*_functions/s21_*.c
S21_STRING_H=s21_*.h
S21_STRING_O=s21_*.o
TESTS=*_test
GCOV=-fprofile-arcs -ftest-coverage
CHFLAGS=-lcheck

ifeq ($(shell uname -s),Linux)
	CHFLAGS+=-lsubunit -lm
endif

all: s21_string.a

s21_string.a:
	$(CC) $(CFLAGS) -c $(S21_STRING_C)
	ar rc s21_string.a $(S21_STRING_O)
	ranlib s21_string.a
	rm *.o

s21_covered:
	$(CC) $(S21_STRING_C) -c $(CHFLAGS) $(CFLAGS) --coverage
	ar rc s21_string.a $(S21_STRING_O)
	ranlib s21_string.a

style:
	clang-format -style=google -i */*.c *.h
	clang-format -style=google -n */*.c *.h


test: clean s21_covered
	$(CC) tests/$(TESTS).c tests.c -c $(FLAGS) --coverage
	$(CC) -o test_main tests.o $(TESTS).o s21_string.a -lcheck --coverage $(FLAGS) $(TEST_FLAGS) -lgcov
	./test_main
clean:
	rm -rf test_main *.a *.o *.gcda *.gcno *.gcov *.info *.html gcov_report

rebuild: clean all

gcov_report: test
	./test_main
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o gcov_report s21_string.info
	open gcov_report/index.html

mem: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test_main

else
	leaks --atExit -- ./test_main
endif