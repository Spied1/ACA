OBJS	= main.o CivillianJet.o FighterJet.o UAV.o
SOURCE	= main.cpp CivillianJet.cpp FighterJet.cpp UAV.cpp
HEADER	= CivillianJet.hpp Plain.hpp FighterJet.hpp UAV.hpp
OUT	= a.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	a.exe

a.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

CivillianJet.o: CivillianJet.cpp
	$(CC) $(FLAGS) CivillianJet.cpp 

UAV.o: UAV.cpp
	$(CC) $(FLAGS) UAV.cpp 

FighterJet.o: FighterJet.cpp
	$(CC) $(FLAGS) FighterJet.cpp 

clean:
	rm -f $(OBJS) $(OUT)
