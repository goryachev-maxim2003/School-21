CC = gcc
CCFLAGS = -c -Wall -Werror -Wextra -std=c11
DERECTORY = ../build/

# start: cipher
# 	leaks -atExit -- $(DERECTORY)cipher
# #	$(DERECTORY)cipher

# start2: logging_cipher
# #	leaks -atExit -- $(DERECTORY)logging_cipher
# 	$(DERECTORY)logging_cipher

cipher:	cipher.o
	$(CC) cipher.o -o $(DERECTORY)cipher
cipher.o: cipher.c
	$(CC) $(CCFLAGS) cipher.c

logging_cipher: logging_cipher.o logger.o
	$(CC) logging_cipher.o logger.o  -o $(DERECTORY)logging_cipher
logging_cipher.o: logging_cipher.c logger.h
	$(CC) $(CCFLAGS) logging_cipher.c
logger.o: logger.h logger.c log_levels.h
	$(CC) $(CCFLAGS) logger.c

clean:
	rm *.o $(DERECTORY)*