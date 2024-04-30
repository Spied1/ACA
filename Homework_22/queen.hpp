#include"chess_piece.hpp"

class queen : public chess_piece
{
public:
	queen(bool side);

	void make_move(std::string move_to) override;
};