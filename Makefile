#
#
#

CC=clang++

main: lib
	$(CC) -g -o main main.cpp -L./ -lsamp -lsocket
lib:
	$(CC) -c -o sampserversdata.o SampServersData.cpp
	$(CC) -c -o libsamp.o LibSamp.cpp 
	ar rvs libsamp.a libsamp.o sampserversdata.o
clean:
	rm main libsamp.a *.o
