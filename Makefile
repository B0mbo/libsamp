#
# libsamp
#

CC=clang++
PRJ=samp
DBG=

main: lib
	$(CC) $(DBG) -o $(PRJ) main.cpp -L./ -l$(PRJ) -lsocket
	rm *.o

lib:
	$(CC) $(DBG) -c -o sampserversdata.o SampServersData.cpp
	$(CC) $(DBG) -c -o lib$(PRJ).o LibSamp.cpp
	ar rc lib$(PRJ).a lib$(PRJ).o sampserversdata.o

clean:
	rm  lib$(PRJ).a *.o
