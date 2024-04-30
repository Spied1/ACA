#include"knight.hpp"
#include<iostream>

knight::knight(bool side) :chess_piece("knight", side)
{

}

void knight::make_move(std::string move_to)
{
	std::cout << "making move :" << move_to;
}