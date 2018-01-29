CFLAGS=-Wall -Werror -std=c++11 -I../../src

all:test

test: test.o
	g++ -Wall -Werror -g $^ -o $@ $(CFLAGS)

test.o: test.cc
	g++ -Wall -Werror -g $^ -c -o $@ $(CFLAGS)

%.o: ../../src/%.cc
	g++ -Wall -Werror -g $^ -c -o $@ $(CFLAGS)

clean:
	rm test *.o
