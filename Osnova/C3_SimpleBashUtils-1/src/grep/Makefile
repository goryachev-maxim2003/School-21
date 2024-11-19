CFLAGS = -c -Wall -Werror -Wextra
s21_grep: grep.o
	gcc s21_grep.o -o s21_grep 
grep.o:
	gcc $(CFLAGS) s21_grep.c
clean:
	rm -rf *.o
	rm s21_grep