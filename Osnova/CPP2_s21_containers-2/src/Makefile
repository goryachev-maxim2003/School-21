CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra 
S21_CONTAINERS_CPP = containers/*/s21_*.cpp
S21_CONTAINERS_O = s21_*.o
TEST=test
TEST_FLAGS = -lgtest -lgcov

all: test

test_compile:
	$(CC) tests/test.cpp $(FLAGS) $(TEST_FLAGS) -o $(TEST) --coverage
test: test_compile
	./$(TEST)
one_test:
	$(CC) tests/test.cpp $(FLAGS) $(TEST_FLAGS) -o $(TEST) --coverage
	./$(TEST) --gtest_filter=s21_set.merge
mem_one_test: one_test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST)
else
	leaks --atExit -- ./$(TEST)
endif
clean:
	rm -rf test *.a *.o *.gcda *.gcno *.gcov *.info *.html report
gcov_report: test
	lcov -t "s21_matrix_oop" -o s21_matrix_oop.info -c -d .
	genhtml -o report s21_matrix_oop.info
	open report/index.html

mem_test: test_compile
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST)
else
	leaks --atExit -- ./$(TEST)
endif