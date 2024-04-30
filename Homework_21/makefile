OBJS	= main.o Animal.o Cat.o Dog.o Eagle.o Lion.o Horse.o
SOURCE	= main.cpp Animal.cpp Cat.cpp Dog.cpp Eagle.cpp Lion.cpp Horse.cpp
HEADER	= Animal.hpp Cat.hpp Dog.hpp Eagle.hpp Horse.hpp Lion.hpp
OUT	= a.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	a.exe

a.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Animal.o: Animal.cpp
	$(CC) $(FLAGS) Animal.cpp 

Cat.o: Cat.cpp
	$(CC) $(FLAGS) Cat.cpp 

Dog.o: Dog.cpp
	$(CC) $(FLAGS) Dog.cpp 

Eagle.o: Eagle.cpp
	$(CC) $(FLAGS) Eagle.cpp 

Lion.o: Lion.cpp
	$(CC) $(FLAGS) Lion.cpp 

Horse.o: Horse.cpp
	$(CC) $(FLAGS) Horse.cpp 

clean:
	rm -f $(OBJS) $(OUT)
