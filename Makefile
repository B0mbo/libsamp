#
# libsamp
#

CC=clang++

main: lib
	$(CC) -g -o main main.cpp -L./ -lsamp -lsocket
lib:
	$(CC) -g -c -o sampserversdata.o SampServersData.cpp
	$(CC) -g -c -o libsamp.o LibSamp.cpp
	ar rc libsamp.a libsamp.o sampserversdata.o

clean:
	rm main libsamp.a *.o
