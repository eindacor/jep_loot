CC=g++

all: jeploot.o jeploot.h
	$(CC) -shared -o libjeploot.so jeploot.o
	sudo cp libjeploot.so /lib
	
jeploot.o: jeploot.h
	$(CC) -fPIC -c jeploot.cpp
	
clean:
	rm *.o