#include"bishop.hpp"
#include<iostream>

bishop::bishop(bool side) :chess_piece("bishop", side)
{

}

void bishop::make_move(std::string move_to)
{
	std::cout << "making move :" << move_to;
}