#include"pawn.hpp"
#include<iostream>

pawn::pawn(bool side) :chess_piece("pawn", side)
{

}

void pawn::make_move(std::string move_to)
{
	std::cout << "making move :" << move_to;
}