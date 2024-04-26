CFLAGS = #-Wall -Werror -Wextra
s21_cat: cat.o
	gcc s21_cat.o -o cat/s21_cat
	./s21_cat cat/file.txt
	
cat.o:
	gcc $(CFLAGS) cat/s21_cat.c -o s21_cat
clean:
	rm -rf *.o
	rm cat/s21_cat
	rm grep/s21_grep