#pragma once
#include<string>

class chess_piece
{
private:
	bool m_side;
	std::string m_name;

public:
	chess_piece(std::string name, bool side);

	virtual void make_move(std::string move_to) = 0;

	virtual ~chess_piece();
};