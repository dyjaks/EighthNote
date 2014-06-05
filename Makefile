CC=gcc
CFLAGD=-I

all: main

main: base.cpp
	g++ -g base.cpp -o EighthNote `pkg-config --cflags --libs gtk+-2.0`

clean:
	rm -f *.o EighthNote