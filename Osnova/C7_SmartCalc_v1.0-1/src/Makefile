CC=gcc
FLAGS=-std=c11 -Wall -Werror -Wextra
TEST_FLAGS=-lm
S21_SmartCalc_C=s21_*.c
S21_SmartCalc_H=s21_*.h
S21_SmartCalc_O=s21_*.o
TESTS=tests
TARGET = Calculator_v1.0

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS+=-lsubunit
endif

all: install
	open ../build/$(TARGET).app
dvi:
	@doxygen Doxyfile
	open doсumentation/html/index.html

s21_SmartCalc.a:
	$(CC) $(S21_SmartCalc_C) -c $(FLAGS)
	ar rc s21_SmartCalc.a $(S21_SmartCalc_O)
	ranlib s21_SmartCalc.a

s21_covered:
	$(CC) $(S21_SmartCalc_C) -c $(FLAGS) --coverage
	ar rc s21_SmartCalc.a $(S21_SmartCalc_O)
	ranlib s21_SmartCalc.a

style:
	clang-format -style=google -i test/*.c *.c *.h
	clang-format -style=google -n test/*.c *.c *.h

test: clean s21_covered
	$(CC) test/$(TESTS)*.c $(TESTS).c -c $(FLAGS) --coverage
	$(CC) -o $(TESTS) $(TESTS)*.o s21_SmartCalc.a -lcheck --coverage $(FLAGS) $(TEST_FLAGS) -lgcov
	./$(TESTS)

mem_test: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TESTS)
else
	leaks --atExit -- ./$(TESTS)
endif

clean:
	rm -rf $(TESTS) *.a *.o *.gcda *.gcno *.gcov *.info *.html report my_test doсumentation

gcov_report: test
	lcov -t "s21_SmartCalc" -o s21_SmartCalc.info -c -d .
	genhtml -o report s21_SmartCalc.info
	open report/index.html

my_test: s21_SmartCalc.a
	$(CC) $(FLAGS) my_test.c s21_SmartCalc.a -lm -o my_test
	./my_test

mem_my_test: s21_SmartCalc.a
	$(CC) $(FLAGS) my_test.c s21_SmartCalc.a -lm -o my_test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./my_test
else
	leaks --atExit -- ./my_test
endif

#sudo apt install qtbase5-dev qt5-qmake
#sudo strip --remove-section=.note.ABI-tag /usr/lib64/libQt5Core.so.5
#sudo -i для перехода на root
#su - username обратно
#strip --remove-section=.note.ABI-tag /usr/lib/x86_64-linux-gnu/libQt5Core.so.5

install:       
	echo "Installation of $(TARGET).app:"
	mkdir -p ../build
	cd SmartCalc/ && qmake && make && make clean && rm -rf Makefile && mv SmartCalc.app ../../build/$(TARGET).app
	echo "Installation completed! You can find app in the ../build/ folder!"

uninstall:
	@rm -rf ../build
	@echo "Uninstall completed!"
dist: install
	mkdir -p ../dist
	@cp -R ../build/$(TARGET).app ../dist
	@cp -R . ../dist/src
	@cd ../dist && tar cvzf $(TARGET).tgz *
	@cd ../dist && rm -rf $(TARGET).app
	@rm -rf ../dist/src
	echo "Archive creation completed successfully!"
	
	