OBJS1 	= main.o init.o preprocessing.o curves.o tempother.o metrics.o assign.o lsh.o update.o silhouette.o
CC		= g++
CFLAGS  = -std=c++11 -Wall -g -fpic -fPIC
TARGET = main1



#main: include/init.h
#	$(CC) $(CFLAGS) -o main1 src/main.cpp

#main1: 
#	$(CC) $(CFLAGS) -o main1 
#cube: $(OBJS2)
#	$(CC) $(CFLAGS) -o cube $(OBJS2)


#main_lsh.o: src/main_lsh.cpp include/read_functions.h include/point.h include/main_functions.h include/hashtable_lsh.h include/defines.h include/print_functions.h
#	$(CC) $(CFLAGS) -c src/main_lsh.cpp
#read_functions.o: src/read_functions.cpp include/point.h include/defines.h
#	$(CC) $(CFLAGS) -c src/read_functions.cpp

.PHONY : all
all: $(TARGET)
main1: $(OBJS1)
	$(CC) $(CFLAGS) -o main1 $(OBJS1)
main.o: src/main.cpp include/libraries.h include/preprocessing.h include/curves.h include/init.h include/metrics.h include/clustering.h include/assign.h include/lsh.h 
	$(CC) $(CFLAGS) -c src/main.cpp

preprocessing.o: src/preprocessing.cpp include/libraries.h
	$(CC) $(CFLAGS) -c src/preprocessing.cpp

curves.o: src/curves.cpp include/libraries.h
	$(CC) $(CFLAGS) -c src/curves.cpp
init.o: src/init.cpp include/libraries.h include/preprocessing.h
	$(CC) $(CFLAGS) -c src/init.cpp
metrics.o: src/metrics.cpp include/libraries.h
	$(CC) $(CFLAGS) -c src/metrics.cpp
tempother.o: src/tempother.cpp include/libraries.h
	$(CC) $(CFLAGS) -c src/tempother.cpp
assign.o: src/assign.cpp include/libraries.h include/preprocessing.h
	$(CC) $(CFLAGS) -c src/assign.cpp
lsh.o: src/lsh.cpp include/libraries.h include/preprocessing.h
	$(CC) $(CFLAGS) -c src/lsh.cpp
update.o: src/update.cpp include/libraries.h include/preprocessing.h
	$(CC) $(CFLAGS) -c src/update.cpp
silhouette.o: src/silhouette.cpp include/libraries.h include/preprocessing.h
	$(CC) $(CFLAGS) -c src/silhouette.cpp