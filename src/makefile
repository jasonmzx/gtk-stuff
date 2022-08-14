
all: main

gtkflags1=`pkg-config --cflags gtk+-3.0`
gtkflags2=`pkg-config --libs gtk+-3.0`

errflags= -Wall -Wextra

main: main.c
		# g++ ${gtkflags} ${errflags} -o a.exe main.cpp

		# very important gtkflags2 comes after everything for some reason ??? 
		gcc ${gtkflags1} ${errflags} -o a main.c ${gtkflags2}

clean:
		rm *.exe 