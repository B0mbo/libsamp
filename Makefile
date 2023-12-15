#
#
#

CC=clang++

main: lib
	$(CC) -o main main.cpp -L./ -lsocket -lsamp
lib:
	$(CC) -c -o sampserversdata.o SampServersData.cpp
	$(CC) -c -o libsamp.o LibSamp.cpp 
	ar rvs libsamp.a libsamp.o sampserversdata.o
clean:
	rm main libsamp.a *.o
