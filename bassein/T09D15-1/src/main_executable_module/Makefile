#gcc - Wall - Werror - Wextra - std = c11 yet_another_decision_module / decision.c data_libs/*.c main_executable_module/*.c data_module/data_process.c -o execute
#gcc -Wall -Werror -Wextra -std=c11 ../yet_another_decision_module/decision.c ../data_libs/*.c ../main_executable_module/*.c ../data_module/data_process.c -o execute
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
data_io = ../data_libs/data_io
data_process = ../data_module/data_process
decision = ../yet_another_decision_module/decision
data_stat = ../data_libs/data_stat
SOURCES = main_executable_module.c sort.c $(data_io).c $(data_process).c $(decision).c $(data_stat).c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = Quest_3
DIRECTORY = ../../build/

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) #main_executable_module.o sort.o data_io.o data_process.o decision.o
	$(CC) $(OBJECTS) -o $(DIRECTORY)$(EXECUTABLE)
main_executable_module.o: main_executable_module.c sort.h $(data_io).h $(data_process).h $(decision).h
	$(CC) $(CFLAGS) main_executable_module.c
sort.o: sort.c sort.h
	$(CC) $(CFLAGS) sort.c
data_io.o: $(data_io).c $(data_io).h
	$(CC) $(CFLAGS) $(data_io).c
data_process.o: $(data_process).c $(data_process).h $(data_stat).h
	$(CC) $(CFLAGS) $(data_process).c
decision.o: $(decision).c $(decision).h $(data_stat).c
	$(CC) $(CFLAGS) $(decision).c
clean:
	rm *.o $(OBJECTS) $(DIRECTORY)Quest* $(DIRECTORY)*.a $(DIRECTORY)*.so
rebuild: clean all

data_stat.a: 
	$(CC) $(CFLAGS) $(data_stat).c
	ar rc $(DIRECTORY)libdata_stat.a data_stat.o
	ranlib $(DIRECTORY)libdata_stat.a
build_with_static: data_stat.a #main_executable_module.o sort.o $(data_io).o $(data_process).o $(decision).o $(DIRECTORY)libdata_stat.a
	$(CC) $(CFLAGS) main_executable_module.c sort.c $(data_io).c $(data_process).c $(decision).c
#	$(CC) -o $(DIRECTORY)Quest_5 -L$(DIRECTORY) -ldata_stat  main_executable_module.o sort.o $(data_io).o $(data_process).o $(decision).o 
	$(CC) -o $(DIRECTORY)Quest_5 -L$(DIRECTORY) -ldata_stat  main_executable_module.o sort.o data_io.o data_process.o decision.o 

data_process.so:
#	$(CC) $(CFLAGS) -fPIC $(data_process).c 
#	$(CC) -shared -o $(DIRECTORY)libdata_process.so data_process.o
	$(CC) $(CFLAGS) -fPIC -shared $(data_process).c -o $(DIRECTORY)libdata_process.so
build_with_dynamic: data_process.so
	$(CC) $(CFLAGS) main_executable_module.c sort.c $(data_io).c $(data_stat).c $(decision).c
#	$(CC) -o $(DIRECTORY)Quest_6 -L$(DIRECTORY) -ldata_process main_executable_module.o sort.o data_io.o data_stat.o decision.o 
	$(CC) -o $(DIRECTORY)Quest_6 main_executable_module.o sort.o data_io.o data_stat.o decision.o  -L$(DIRECTORY) -ldata_process