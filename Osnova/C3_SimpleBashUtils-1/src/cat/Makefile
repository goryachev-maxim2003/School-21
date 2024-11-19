CFLAGS = -c -Wall -Werror -Wextra
s21_cat: cat.o
	gcc s21_cat.o -o s21_cat 
cat.o:
	gcc $(CFLAGS) s21_cat.c
clean:
	rm -rf *.o
	rm s21_cat