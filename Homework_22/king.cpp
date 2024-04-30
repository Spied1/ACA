#include"king.hpp"
#include<iostream>

king::king(bool side) :chess_piece("king", side)
{

}

void king::make_move(std::string move_to)
{
	std::cout << "making move :" << move_to;
}