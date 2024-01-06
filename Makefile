#
# libsamp
#

CC=clang++
PRJ=samp

main: lib
	$(CC) -g -o $(PRJ) main.cpp -L./ -l$(PRJ) -lsocket
	rm *.o

lib:
	$(CC) -g -c -o sampserversdata.o SampServersData.cpp
	$(CC) -g -c -o lib$(PRJ).o LibSamp.cpp
	ar rc lib$(PRJ).a lib$(PRJ).o sampserversdata.o

clean:
	rm  lib$(PRJ).a *.o
