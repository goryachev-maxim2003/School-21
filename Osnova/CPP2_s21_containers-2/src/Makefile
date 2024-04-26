CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra 
S21_CONTAINERS_CPP = containers/*/s21_*.cpp
S21_CONTAINERS_O = s21_*.o
TEST=test
TEST_FLAGS = -lgtest -lgcov

all: test

# s21_containers.a:
# 	$(CC) $(S21_CONTAINERS_CPP) -c $(FLAGS) --coverage
# 	ar rc s21_containers.a $(S21_CONTAINERS_O)
# 	ranlib s21_containers.a

test:
	$(CC) tests/test.cpp $(FLAGS) $(TEST_FLAGS) -o $(TEST) --coverage
	./$(TEST)
clean:
	rm -rf test *.a *.o *.gcda *.gcno *.gcov *.info *.html report
gcov_report: test
	lcov -t "s21_matrix_oop" -o s21_matrix_oop.info -c -d .
	genhtml -o report s21_matrix_oop.info
	open report/index.html

mem_test: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST)
else
	leaks --atExit -- ./$(TEST)
endif