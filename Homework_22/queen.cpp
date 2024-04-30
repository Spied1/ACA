#include"queen.hpp"
#include<iostream>

queen::queen(bool side) :chess_piece("queen", side)
{

}

void queen::make_move(std::string move_to)
{
	std::cout << "making move :" << move_to;
}