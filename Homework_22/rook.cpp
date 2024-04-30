#include"rook.hpp"
#include<iostream>

rook::rook(bool side) :chess_piece("rook", side)
{

}

void rook::make_move(std::string move_to)
{
	std::cout << "making move :" << move_to;
}