CC=g++ 
CFLAGS=-std=c++11

all: JSON

JSON:	testing.cpp
	$(CC) $(CFLAGS) testing.cpp -o JSON


clean:
	rm -rf *o JSON

run:	testing.cpp
	$(CC) $(CFLAGS) testing.cpp -o JSON
	./JSON
	rm -rf *o JSON