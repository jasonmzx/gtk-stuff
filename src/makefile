
all: maincpp

gtkflags1=`pkg-config --cflags gtk+-3.0`
gtkflags2=`pkg-config --libs gtk+-3.0`

magickflags1=`Magick++-config --cxxflags --cppflags`
magickflags2=`Magick++-config --ldflags --libs` 

errflags= -Wall -Wextra

inputfile   = main.cpp headertest/uwu.h headertest/uwu.cpp headers/CImg.h
#outputfile  = nyah.exe #For Windows
outputfile = nyan-linux #For Ubuntu

maincpp: main.cpp

		g++ ${gtkflags1} ${magickflags1} ${errflags} -o ${outputfile} ${inputfile} ${gtkflags2} ${magickflags2} -lX11

clean:
		rm *.exe 
		rm ${outputfile}





# mainc: main.c
# 		# very important gtkflags2 comes after everything for some reason ??? 
# 		gcc ${gtkflags1} ${errflags} -o a main.c ${gtkflags2}

# maincpp: main.cpp
# 		# g++ ${gtkflags} ${errflags} -o a.exe main.cpp

# 		# very important gtkflags2 comes after everything for some reason ??? 
# 		g++ ${gtkflags1} ${magickflags1} ${errflags} -o b main.cpp ${gtkflags2} ${magickflags2}


# # install from source and stuff just works 
# # https://stackoverflow.com/a/68507605
# magik: magic.cpp 
		
# 		g++ ${magickflags1} -O2 -o demo magic.cpp ${magickflags2}
