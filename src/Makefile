CFLAGS=-Wall -Werror -std=c++11

all:main

main: main.o csv_reader.o database.o
	g++ -Werror -Wall -g $^ -o $@ $(CFLAGS)

%.o: %.cc
	g++ -Werror -Wall -g $^ -c -o $@ $(CFLAGS)

clean:
	rm main *.o
