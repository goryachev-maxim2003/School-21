CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra 
TEST_FLAGS=-lgtest -lgcov
S21_MATRIX_CPP=s21_*.cpp
S21_MATRIX_H=s21_*.h
S21_MATRIX_O=s21_*.o
TEST=test

all: s21_matrix_oop.a test

s21_matrix_oop.a:
	$(CC) $(S21_MATRIX_CPP) -c $(FLAGS) --coverage
	ar rc s21_matrix_oop.a $(S21_MATRIX_O)
	ranlib s21_matrix_oop.a
test: s21_matrix_oop.a
	$(CC) test.cpp s21_matrix_oop.a $(FLAGS) $(TEST_FLAGS) -o $(TEST) --coverage
	./$(TEST)
gcov_report: test
	lcov -t "s21_matrix_oop" -o s21_matrix_oop.info -c -d .
	genhtml -o report s21_matrix_oop.info
	open report/index.html
clean:
	rm -rf test *.a *.o *.gcda *.gcno *.gcov *.info *.html report
mem_test: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST)
else
	leaks --atExit -- ./$(TEST)
endif