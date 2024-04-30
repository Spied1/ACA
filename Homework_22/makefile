OBJS	= main.o bishop.o chess_piece.o king.o knight.o queen.o rook.o pawn.o
SOURCE	= main.cpp bishop.cpp chess_piece.cpp king.cpp knight.cpp queen.cpp rook.cpp pawn.cpp
HEADER	= bishop.hpp chess_piece.hpp king.hpp knight.hpp queen.hpp rook.hpp pawn.hpp
OUT	= a.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	a.exe

a.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

bishop.o: bishop.cpp
	$(CC) $(FLAGS) bishop.cpp 

chess_piece.o: chess_piece.cpp
	$(CC) $(FLAGS) chess_piece.cpp 

king.o: king.cpp
	$(CC) $(FLAGS) king.cpp 

knight.o: knight.cpp
	$(CC) $(FLAGS) knight.cpp 

queen.o: queen.cpp
	$(CC) $(FLAGS) queen.cpp 

rook.o: rook.cpp
	$(CC) $(FLAGS) rook.cpp 

pawn.o: pawn.cpp
	$(CC) $(FLAGS) pawn.cpp 

clean:
	rm -f $(OBJS) $(OUT)
