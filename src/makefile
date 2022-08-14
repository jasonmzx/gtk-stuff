
all: main

gtkflags=`pkg-config --cflags --libs gtk+-3.0`

errflags= -Wall -Wextra

main: main.c
		# g++ ${gtkflags} ${errflags} -o a.exe main.cpp
		gcc `pkg-config --cflags gtk+-3.0` -o a main.c `pkg-config --libs gtk+-3.0`

clean:
		rm *.exe 